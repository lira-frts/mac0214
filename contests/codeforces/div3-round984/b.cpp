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
    ll n, k; cin >> n >> k;
    map<ll, ll> mp;
    for(ll i = 0; i < k; i++){
        ll b, c; cin >> b >> c;
        mp[b] += c;
    }
    vll v;
    for(auto &[key, val]: mp) v.pb(val);
    sort(all(v));
    ll resp = 0;
    ll sz = v.size(); 
    for(ll i = sz-1; i >= max(sz-n, 0LL); i--) resp += v[i];
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
