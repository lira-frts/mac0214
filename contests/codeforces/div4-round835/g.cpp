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

ll n, a, b;

void dfs(ll v, vvpll &E, vll &vis, vll &XOR){
    vis[v] = 1;
    for(auto [u, w]: E[v]){
        if(vis[u]) continue;
        if(u == b) continue;
        XOR[u] = XOR[v] ^ w;
        dfs(u, E, vis, XOR);
    }
}

void solve(){
    cin >> n >> a >> b; a--, b--;
    vvpll E(n);
    for(ll i = 0; i < n-1; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E[u].pb({v, w}), E[v].pb({u, w});
    }

    vll vis(n, 0), XOR(n, 0);
    dfs(a, E, vis, XOR);

    set<ll> XOR_A;
    for(ll i = 0; i < n; i++)
        if(vis[i]) XOR_A.insert(XOR[i]);

    for(ll i = 0; i < n; i++) vis[i] = 0, XOR[i] = 0;
    dfs(b, E, vis, XOR);
    
    for(ll i = 0; i < n; i++){
        if(i == b) continue;
        if(XOR_A.find(XOR[i]) != XOR_A.end()){
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
