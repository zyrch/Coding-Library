// template ends here
// the code assumes graph to have zero vertices with odd degree

const int nax = 2e5 + 5;
vi AdjL[nax];
int vis[nax], eu[nax], ev[nax];
vi ans;
void get_euler(int u) {
    while(sz(AdjL[u])) {
	int i = AdjL[u].back();
	AdjL[u].pop_back();
	if (!vis[i]) {
	    vis[i] = 1;
	    get_euler(ev[i] ^ eu[i] ^ u);
	}
    }
    ans.pb(u);
}
    

int main(){
    fast_cin();
    
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
	cin >> a >> b, --a, --b;
	ev[i] = a, eu[i] = b;
	AdjL[a].pb(i);
	AdjL[b].pb(i);
    }
    
    for (int i = 0; i < n; ++i) {
	if (AdjL[i].size() & 1) {
	    cout << "IMPOSSIBLE\n";
	    return 0;
	}
    }
    
    get_euler(0);
    reverse(all(ans));
    if (sz(ans) != m + 1) {
	cout << "IMPOSSIBLE";
	return 0;
    }else trav(v, ans) cout << v + 1 << " ";
    
    return 0;
}

