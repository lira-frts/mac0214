#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

using vll = vector<int>;
using pll = pair<int, int>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

int gcd(int a, int b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

void bfs(vvll &E, vll &dist, int v){
    queue<int> q;
    dist[v] = 0; q.push(v);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int u: E[v]){
            if(dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vll ks(k);
    for(auto &ki: ks) cin >> ki, ki--;
    vvll E(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        E[u].push_back(v); E[v].push_back(u);
    }
    
    vll dist1(n, -1), dist2(n, -1);
    bfs(E, dist1, 0); bfs(E, dist2, n-1);
    
    int soma = 0;
    for(int ki: ks) soma += dist2[ki];
        
    int a = dist1[n-1], b = 1;
    for(int ki: ks){
        int aa = (k-1) * dist1[ki] + soma - dist2[ki], bb = k-1;
        if((double) aa/bb < (double) a/b) a = aa, b = bb;
    }
    cout << a/gcd(a,b) << '/' << b/gcd(a,b) << '\n';
}

signed main(){
    MAC0214 muito coxa
    int t=1;
    while(t--) solve();
    return 0;
}
