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
    ll n; cin >> n;
    map<ll, vll> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x].pb(i);
    }
    vll resp(n);
    for(auto &[val, v]: mp){
        resp[v[0]] = - 1;
        for(ll i = 1; i < v.size(); i++) resp[v[i]] = v[i-1]+1;
    }
    for(ll x: resp) cout << x << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
