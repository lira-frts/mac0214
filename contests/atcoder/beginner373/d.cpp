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

const ll INF = 1e18 + 10;

void solve(){
    ll n, m; cin >> n >> m;
    vvpll E(n);
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E[u].push_back({v, w});
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
