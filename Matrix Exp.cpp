// template end here
ll siz;
struct Matrix{
    vector<vector<ll>> mat;
    int nax;
    Matrix (int siz) {
	nax = siz;
	mat.resize(nax, vl(nax));
    }
    Matrix operator*(Matrix other){
        Matrix ans(other.nax);
        for(int i = 0; i < nax; i++){
            for(int j = 0; j < nax; j++){
                for(int k = 0; k < nax; k++) {
                    ans.mat[i][j] = (ans.mat[i][j]+(mat[i][k]*other.mat[k][j])%mod)%mod;
		}
            }
        }
        return ans;
    }
};

Matrix fast_exp(Matrix base,ll power){
    Matrix x=base,ans(siz);
    fo(i, n) {
	ans.mat[i][i] = 1;
    }
    ll cnt = power;
    while(cnt){
        if (cnt&1) ans=(ans*x);
        x=(x*x);
        cnt>>=1;
    }
    return ans;
}
