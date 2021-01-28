// template end here
struct Segtree {
    int siz;
    vector<ll> tree;
    vector<ll> delta;
    vector<ll> lo;
    vector<ll> hi;
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    Segtree(int n, vector<ll> arr) {
	siz = 4 * n;
	tree.resize(siz + 1);
	delta.resize(siz + 1);
	lo.resize(siz + 1);
	hi.resize(siz + 1);
	build(1, n, arr, 1);
    }
    
    void build(ll l, ll r, vector<ll> &arr, ll idx) {
	
	lo[idx] = l, hi[idx] = r;
	if (l == r) {
	    tree[idx] = arr[l - 1];
	    return;
	}
	
	ll mid = (l + r)/2;
	build(l, mid, arr, 2 * idx);
	build(mid + 1, r, arr, 2 * idx + 1);    
	merge(idx);
    }
    
    void update(ll idx, ll l, ll r, ll val) {
	if (hi[idx] < l || lo[idx] > r) {
	    return;
	}
	if (l <= lo[idx] && hi[idx] <= r) {
	    delta[idx] += val;
	    return;
	}
	prop(idx);
	update(2 * idx, l, r, val);
	update(2 * idx + 1, l, r, val);
	merge(idx);
    }
    
    ll query(ll idx, ll l, ll r) {
	if (hi[idx] < l || lo[idx] > r) {
	    return INF;
	}
	if (l <= lo[idx] && hi[idx] <= r) {
	    return tree[idx] + delta[idx];
	}
	
	prop(idx);
	ll Left = query(2 * idx, l, r);
	ll Right = query(2 * idx + 1, l, r);
	merge(idx);
	return min(Left, Right);
    }
    
    void merge(ll idx) {
	tree[idx] = min(tree[2 * idx] + delta[2 * idx], tree[2 * idx + 1] + delta[2 * idx + 1]);
    }
    
    void prop(ll idx) {
	delta[2 * idx] += delta[idx];
	delta[2 * idx + 1] += delta[idx];
	delta[idx] = 0;
    }

};

int main() {
    fast_cin();
    
    
    return 0;
}
