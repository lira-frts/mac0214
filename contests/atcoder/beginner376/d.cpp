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

void solve(){
    ll n, m; cin >> n >> m;
    vvll E(n);
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v; u--, v--;
        E[u].pb(v);
    }
    vll vis(n, 0);
    queue<pll> q;
    vis[0] = 1; q.push({0, 1});
    while(!q.empty()){
        auto [v, dist] = q.front(); q.pop();
        for(auto u: E[v]){
            if(u == 0){
                cout << dist << '\n';
                return;
            }
            if(!vis[u]){
                vis[u] = 1;
                q.push({u, dist+1});
            }
        }
    }
    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
