// template end here
struct Segtree {
    int siz;
    vector<ll> sum;
    vector<ll> delta;
    vector<ll> delta2;
    vector<ll> lo;
    vector<ll> hi;
    Segtree(int n, vector<ll> arr) {
	siz = 4 * n;
	sum.resize(siz + 1);
	delta.resize(siz + 1);
	delta2.resize(siz + 1);
	lo.resize(siz + 1);
	hi.resize(siz + 1);
	build(1, n, arr, 1);
    }
    
    void build(ll l, ll r, vector<ll> &arr, ll idx) {
	lo[idx] = l, hi[idx] = r;
	if (l == r) {
	    sum[idx] = arr[l - 1];
	    return;
	}
	
	ll mid = (l + r)/2;
	build(l, mid, arr, 2 * idx);
	build(mid + 1, r, arr, 2 * idx + 1);
	merge(idx);
    }
    // range update
    void update(ll idx, ll l, ll r , ll val) {
	if (r < lo[idx] || l > hi[idx]) return;
	if (l <= lo[idx] && hi[idx] <= r) {
	    delta[idx] += val;
	    return;
	}
	prop(idx);
	update(2 * idx, l, r, val);
	update(2 * idx + 1, l, r, val);
	merge(idx);
    }
    
    // range set
    void update2(ll idx, ll l, ll r , ll val) {
	if (r < lo[idx] || l > hi[idx]) return;
	if (l <= lo[idx] && hi[idx] <= r) {
	    delta[idx] = 0;
	    delta2[idx] = val;
	    return;
	}
	prop(idx);
	update2(2 * idx, l, r, val);
	update2(2 * idx + 1, l, r, val);
	merge(idx);
    }
    
    ll query(ll idx, ll l, ll r) {
	if (r < lo[idx] || l > hi[idx]) return 0;
	
	if (l <= lo[idx] && hi[idx] <= r) {
	    if (delta2[idx])
		return delta2[idx] * (hi[idx] - lo[idx] + 1) + delta[idx] * (hi[idx] - lo[idx] + 1);
	    return sum[idx] + delta[idx] * (hi[idx] - lo[idx] + 1);
	}
	
	prop(idx);
	ll sumLeft = query(2 * idx, l, r);
	ll sumRight = query(2 * idx + 1, l, r);
	//~ debug(sumRight, sumLeft, idx);
	merge(idx);
	return sumLeft + sumRight;
    }
    
    void prop(ll idx) {
	if (delta2[idx] != 0) {
	    delta2[2 * idx] = delta2[idx];
	    delta2[2 * idx + 1] = delta2[idx];
	    delta2[idx] = 0;
	    delta[2 * idx] = delta[2 * idx + 1] = 0;
	}
	delta[2 * idx] += delta[idx];
	delta[2 * idx + 1] += delta[idx];
	delta[idx] = 0;
    }
    
    void merge(ll idx) {
	sum[idx] = 0;
	if (delta2[2 * idx]) {
	    sum[idx] += delta2[2 * idx] * (hi[2 * idx] - lo[2 * idx] + 1);
	}else {
	    sum[idx] += sum[2 * idx];
	}
	sum[idx] += delta[2 * idx] * (hi[2 * idx] - lo[2 * idx] + 1);
	
	if (delta2[2 * idx + 1]) {
	    sum[idx] += delta2[2 * idx + 1] * (hi[2 * idx + 1] - lo[2 * idx + 1] + 1);
	}else {
	    sum[idx] += sum[2 * idx + 1];
	}
	sum[idx] += delta[2 * idx + 1] * (hi[2 * idx + 1] - lo[2 * idx + 1] + 1);
    }
 
};
