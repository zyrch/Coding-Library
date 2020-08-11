// template end here
const int N = 2e6 + 5;
 
vl factorialNumInverse(N + 1);
vl naturalNumInverse(N + 1);
vl fact(N + 1);
ll p = mod;
 
void cal_fac() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
	fact[i] = (fact[i - 1] * i) % p;
    }
}
 
void Inverse() {
    naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; ++i) {
	naturalNumInverse[i] = (p - naturalNumInverse[p % i] * (p/i) % p) % p;
    } 
}
 
void factorialInv() {
    factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; ++i) {
	factorialNumInverse[i] = (factorialNumInverse[i - 1] * naturalNumInverse[i]) % p;
    }
}
 
ll nCr(ll n, ll r) {
    if (r == 0 || r == n) return 1;
    return ((fact[n] * factorialNumInverse[n - r]) % p * factorialNumInverse[r]) % p;
}

int main() {
    fast_cin();
    
    cal_fac();
    Inverse();
    factorialInv();
    
    return 0;
}
