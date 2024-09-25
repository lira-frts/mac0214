/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pl = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vlll = vector<lll>;

const ll INF = 1e18;
ll n;

vector<vll> dijkstra(ll inicio, vector<vpl> &E, vll &cavalos){
    vector<vll> dist(n, vll(2, INF)); 
    set<lll> s; s.insert({0, inicio, 0});
    dist[inicio][0] = 0;
    while(!s.empty()){
        auto [dv, v, cv] = *s.begin(); s.erase(s.begin());
        bool c = cv || cavalos[v];
        for(auto [u, w]: E[v]){
            ll du = dist[v][cv] + (c ? w/2 : w);
            if(dist[u][c] > du){
                s.erase({dist[u][c], u, c});
                dist[u][c] = du;
                s.insert({dist[u][c], u, c});
            } 
        }
    }
    return dist;
}

void solve(){
    ll m, h; cin >> n >> m >> h;
    vector<vpl> E(n);
    vll cavalos(n);
    for(ll i = 0; i < h; i++){ll v; cin >> v; cavalos[--v] = 1;}
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E[u].push_back({v, w}); E[v].push_back({u, w});
    }
    vector<vll> dist1 = dijkstra(0, E, cavalos), dist2 = dijkstra(n-1, E, cavalos);
    ll minimo = INF;
    for(ll i = 0; i < n; i++) minimo = min(minimo, max(min(dist1[i][0], dist1[i][1]), min(dist2[i][0], dist2[i][1])));
    cout << (minimo == INF ? -1 : minimo) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
