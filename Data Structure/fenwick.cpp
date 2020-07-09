// template end here
template <class T>
struct fenwick {
    int siz;
    vector<T> arr;
    
    fenwick(int n) {
	siz = n;
	arr.resize(n + 1);
    }
    
    T sum(int idx) {
	T an = 0;
	while(idx > 0) {
	    an += arr[idx];
	    idx -= idx & -idx;
	}
	return an;
    }
    
    void update(int idx, T delta) {
	while (idx < siz + 1) {
	    arr[idx] += delta;
	    idx += idx & -idx;
	}
    }
    
    T query(ll l, ll r) {
	return sum(r) - sum(l - 1);
    }
};
    

int main() {
    fast_cin();
    
    
    
    return 0;
}
