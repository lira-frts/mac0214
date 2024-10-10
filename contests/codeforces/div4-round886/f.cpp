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

void solve(){
    ll n; cin >> n;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x]++;
    }
    vll v(n+1, 0);
    for(auto &[k, val]: mp)
        for(ll i = k; i <= n; i += k) v[i] += val;
    ll maximo = -1;
    for(ll i = 1; i <= n; i++) maximo = max(maximo, v[i]);
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
