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

void dfs(vvll &E, vll &vis, ll v){
    vis[v] = 1;
    for(ll u: E[v])
        if(!vis[u]) dfs(E, vis, u);
}

void solve(){
    ll n; cin >> n;
    vll v(n);
    for(ll &vi: v) cin >> vi;
    ll cont = 1;
    map<ll, ll> mp;
    vvll E(2*n+10);
    for(ll i = 0; i < n; i++){
        ll l = v[i] + i;
        if(!mp[l]) mp[l] = cont++;
        if(!mp[l+i]) mp[l+i] = cont++;
        E[mp[l]].pb(mp[l+i]);
    }
    vll vis(2*n+10, 0);
    dfs(E, vis, mp[n]);
    ll maximo = 0;
    for(auto &[key, val]: mp)
        if(vis[val]) maximo = max(maximo, key);
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
