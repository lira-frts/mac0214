/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e9;

void solve(){
    ll n, m; cin >> n >> m;
    ll t0, t1, t2; cin >> t0 >> t1 >> t2;
    vector<vector<ll>> E[n];
    for(ll i = 0; i < m; i++){
        ll u, v, l1, l2; cin >> u >> v >> l1 >> l2;
        u--, v--;
        E[u].push_back({v, l1, l2});
        E[v].push_back({u, l1, l2});
    }
    set<pair<ll, ll>> s;
    vector<ll> dist(n, -INF);
    s.insert({t0, n-1});
    for(ll i = 1; i < n; i++) s.insert({-INF, i});
    dist[n-1] = t0;
    while(!s.empty()){
        auto x = *s.rbegin(); s.erase(x);
        ll d = x.first, v = x.second;
        for(auto e: E[v]){
            ll u = e[0], l1 = e[1], l2 = e[2];
            ll nd;
            // tenta ir de busão
            if(d - l1 >= t2 || d <= t1) nd = d - l1;
            // escolhe melhor opção entre ir andando ou fazer a ligação e depois pegar busão
            else nd = max(d - l2, t1 - l1);
            if(dist[u] < nd){
                s.insert({nd, u});
                s.erase({dist[u], u});
                dist[u] = nd;
            }
        }
    }
    cout << (dist[0] >= 0 ? dist[0] : -1) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
