/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll NMAX = 1e9+1;

void solve(){
    ll n; cin >> n;
    map<ll, set<ll>> mp;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        v[i] = x>>2;
        mp[x>>2].insert(x);
    }
    for(ll i = 0; i < n; i++){
        ll x = *mp[v[i]].begin();
        mp[v[i]].erase(x);
        cout << x << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
