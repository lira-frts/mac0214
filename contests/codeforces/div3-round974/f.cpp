/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpll = vector<pll>;
using vlll = vector<lll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

ll c;

void dfs(ll v, vvll &E, vvll &dp, vll &gold, vll &vis){
    if(vis[v]) return;
    vis[v] = 1; 

    if(E[v].size() == 0){
        dp[v][0] = 0, dp[v][1] = gold[v];
        return;
    }

    for(ll u: E[v]) dfs(u, E, dp, gold, vis);

    // não salvando o atual
    dp[v][0] = 0;
    for(ll u: E[v]) dp[v][0] += max(dp[u][0], dp[u][1]);

    // salvando o atual
    dp[v][1] = gold[v];
    for(ll u: E[v]) dp[v][1] += max(dp[u][0], dp[u][1] - 2*c);
}

void solve(){
    ll n; cin >> n >> c;
    vll gold(n), vis(n, 0);
    for(ll i = 0; i < n; i++) cin >> gold[i];
    vvll E(n), dp(n, vll(2));
    for(ll i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v; u--, v--;
        E[v].push_back(u); E[u].push_back(v);
    }
    dfs(0, E, dp, gold, vis);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
