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

ll n, ciclo_inicio, ciclo_fim;

bool dfs(ll v, ll p, vvll &E, vll &vis, vll &ciclo){
    vis[v] = 1;
    for(ll u: E[v]){
        if(u == p) continue;
        if(vis[u]){
            ciclo_fim = v;
            ciclo_inicio = u;
            return 1;
        }
        ciclo[u] = v;
        if(dfs(u, v, E, vis, ciclo)) return 1;
    }
    return 0;
}

vll bfs(ll v, vvll &E){
    vll vis(n), dist(n);
    queue<ll> q;
    dist[v] = 0; q.push(v);
    while(!q.empty()){
        ll v = q.front(); q.pop();
        vis[v] = 1;
        for(ll u: E[v]){
            if(vis[u]) continue;
            dist[u] = dist[v] + 1; vis[u] = 1; q.push(u);
        }
    }
    return dist;
}

void solve(){
    ll a, b; cin >> n >> a >> b; a--, b--;
    vvll E(n);
    for(ll i = 0; i < n; i++){
        ll u, v; cin >> u >> v; u--, v--;
        E[u].pb(v); E[v].pb(u);
    }
    vll vis(n), ciclo(n);
    for(ll i = 0; i < n; i++){
        if(vis[i]) continue;
        if(dfs(i, i, E, vis, ciclo)) break;
    }
    vll dist1 = bfs(a, E), dist2 = bfs(b, E);

    bool flag = 0;
    vll v;
    while(ciclo_fim != ciclo_inicio) v.pb(ciclo_fim), ciclo_fim = ciclo[ciclo_fim];
    v.pb(ciclo_inicio);
    for(ll vi: v)
        if(dist2[vi] < dist1[vi]){
            cout << "yes\n";
            return;
        }
    cout << "no\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
