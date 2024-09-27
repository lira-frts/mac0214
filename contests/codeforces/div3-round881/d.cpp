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

void dfs(ll v, vvll &E, vll &vis, vll &resp){
    vis[v] = 1;
    bool flag = 1;
    for(ll u: E[v])
        if(!vis[u]){
            flag = 0;
            dfs(u, E, vis, resp);
            resp[v] += resp[u];
        }
    if(flag) resp[v] = 1;
}

void solve(){
    ll n; cin >> n;
    vvll E(n);
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v; u--, v--;
        E[u].push_back(v); E[v].push_back(u);
    }
    vll vis(n, 0), resp(n, 0);
    dfs(0, E, vis, resp);
    ll q; cin >> q;
    while(q--){
        ll u, v; cin >> u >> v; u--, v--;
        cout << resp[u] * resp[v] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
