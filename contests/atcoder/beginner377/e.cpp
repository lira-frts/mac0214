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

void dfs(ll x, vll &p, vll &vis, vll &v){
    vis[x] = 1;
    v.pb(x);
    if(!vis[p[x]]) dfs(p[x], p, vis, v);
}

ll exp_mod(ll x, ll n, ll m){
    if(n == 0) return 1;
    ll k = exp_mod(x, n/2, m); k = (k * k) % m;
    if(n % 2) k = (k * x) % m;
    return k;
}

void solve(){
    ll n, k; cin >> n >> k;
    vll p(n);
    for(ll &pi: p) cin >> pi, pi--;
    vll vis(n), v, resp(n);
    for(ll i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, p, vis, v);
        ll sz = v.size();
        for(ll j = 0; j < sz; j++) resp[v[j]] = v[(j+exp_mod(2, k, sz))%sz]+1;
        v.clear();
    }
    for(ll x: resp) cout << x << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
