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
    ll n, q; cin >> n >> q;
    vll v(n+1, 0);
    map<ll, vll> mp;
    mp[0].pb(0);
    for(ll i = 1; i <= n; i++){
        cin >> v[i], v[i] ^= v[i-1];
        mp[v[i]].pb(i);
    }
    while(q--){
        ll l, r; cin >> l >> r;
        if(v[r] == v[l-1]){
            cout << "yes\n";
            continue;
        }
        ll t = *--lower_bound(mp[v[l-1]].begin(), mp[v[l-1]].end(), r);
        ll s = *lower_bound(mp[v[r]].begin(), mp[v[r]].end(), l);
        cout << (s < t ? "yes\n" : "no\n");
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
