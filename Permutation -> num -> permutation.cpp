// template end here
// code is for size - 9

// let x be the number of numbers which have index less than x and are less than x
// now for each number p add x*p! to the result
// so result will look something like : r = x9 * 9! + x8 * 8! + ... + x1 * 1!
// the upper bound on the value of xi is (i - 1), due to this we can get x9 by diving r by 9!
// hence we can build back the permutation by removing numbers in reverse order and placing the at xi-th free position 
// and diving the result by (i!)

int inv(vi &v) {
    int m = 1, r = 0, k = 1*2*3*4*5*6*7*8;
    for (int i = 0; i < 8; i++) {
	int o = v[i];
	int e = (o - __builtin_popcount(m & ((1 << o) - 1)));
	r += e * k;
	k /= 8 - i;
	m |= (1 << o);
    }
    return r;
}

vi perm(int r) {
    vi v(9);
    int m = 1, k = 1*2*3*4*5*6*7*8;
    for (int i = 0; i <= 8; i++) {
	int o = r / k;
	int j = 0, l = 1;
	while (j <= o) {
	    if (!(m & (1 << l))) j++;
	    if (j > o) break;
	    l++;
	}
	v[i] = l;
	if (i == 8) break;
	r %= k;
	k /= 8 - i;
	m |= (1 << l);
    }
    return v;
}
