// template ends here

struct Trie {
    
    ll val;
    Trie *zero = nullptr, *one = nullptr;
    Trie (int va) {
	val = va;
    }
    
    void insert(ll nu, ll in) {
	if (in < 0) return;
	if (nu & (1LL << in)) {
	    if (one == nullptr) {
		one = new Trie(1);
		one->insert(nu, in - 1);
	    }else {
		one->insert(nu, in - 1);
	    }
	}else {
	    if (zero == nullptr) {
		zero = new Trie(0);
		zero->insert(nu, in - 1);
	    }else {
		zero->insert(nu, in - 1);
	    }
	}
    }
	
    
}*root;

ll find_max_xor(ll nu) {
    ll ans = 0;
    Trie *p1, *p2;
    p1 = p2 = root;
    ll le = 33;
    while(~le) {
	//~ debug(le, ans);
	
	if ((1LL << le) & nu) {
	    if (p2->zero != nullptr) {
		ans += 1LL << le;
		p2 = p2->zero;
	    }else if (p2->one != nullptr) {
		p2 = p2->one;
	    }else break;
	    p1 = p1->one;
	}else {
	    if (p2->one != nullptr) {
		ans += 1LL << le;
		p2 = p2->one;
	    }else if (p2->zero != nullptr) {
		p2 = p2->zero;
	    }else break;
	    p1 = p1->zero;
	}
	le--;
    }
    return ans;
}
