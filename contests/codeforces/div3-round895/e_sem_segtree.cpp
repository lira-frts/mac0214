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
    vll v(n);
    for(auto &vi: v) cin >> vi;
    string s; cin >> s;

    ll xor0 = 0, xor1 = 0;
    for(ll i = 0; i < n; i++)
        if(s[i] == '1') xor1 ^= v[i];
        else xor0 ^= v[i];

    for(ll i = 1; i < n; i++) v[i] ^= v[i-1];
    
    ll q; cin >> q;
    while(q--){
        ll x; cin >> x;
        if(x == 1){
            ll l, r; cin >> l >> r; l--, r--;
            ll dif = v[r];
            if(l > 0) dif ^= v[l-1];
            xor0 ^= dif, xor1 ^= dif;
        }
        else{
            ll g; cin >> g;
            if(g == 0) cout << xor0 << ' ';
            if(g == 1) cout << xor1 << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
