/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define pb push_back
#define all(x) x.begin(),x.end()

const ll INF = 1e18 + 10;
bool flag;

void dfs(ll v, vvpll &E, vll &vis, vll &val){
    vis[v] = 1;
    if(val[v] == INF) val[v] = 0;
    for(auto [u, w]: E[v]){
        if(vis[u]){
            if(val[u] != val[v] + w) flag = 0;
            continue;
        }
        val[u] = val[v] + w;
        dfs(u, E, vis, val);
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vvpll E(n);
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E[u].pb({v, w}); E[v].pb({u, -w});
    }
    flag = 1;
    vll val(n, INF), vis(n, 0);
    for(ll i = 0; i < n; i++)
        if(!vis[i]) dfs(i, E, vis, val);

    cout << (flag ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
