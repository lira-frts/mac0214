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

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(a) a.rbegin(), a.rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

ll timer;

void dfs(ll v, ll p, vll &vis, vvll &E, vll &tin, vll &low, vpll &bridges, vll &sz){
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    ll sz2 = 1;
    for(ll u: E[v]){
        if(u == p) continue;
        if(vis[u]) low[v] = min(low[v], tin[u]);
        else{
            dfs(u, v, vis, E, tin, low, bridges, sz);
            low[v] = min(low[v], low[u]);
            if(low[u] > tin[v]) bridges.pb({u, v});
            sz2 += sz[u];
        }
    }
    sz[v] = sz2;
}

void solve(){
    ll n, m; cin >> n >> m;
    vvll E(n);
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v; u--, v--;
        E[u].pb(v), E[v].pb(u);
    }
    vll vis(n), tin(n, -1), low(n, -1), sz(n);
    vpll bridges;
    timer = 0;
    dfs(0, -1, vis, E, tin, low, bridges, sz);
    ll minimo = n*(n-1)/2;
    for(auto &[u, v]: bridges){
        ll sz1 = min(sz[u], sz[v]), sz2 = n-sz1;
        ll qtd = (sz1 * (sz1-1)) / 2 + (sz2 * (sz2 - 1)) / 2;
        minimo = min(minimo, qtd);
    }
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
