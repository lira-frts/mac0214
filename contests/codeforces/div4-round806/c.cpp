/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pl = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vlll = vector<lll>;

void solve(){
    ll n; cin >> n;
    vll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 0; i < n; i++){
        ll b; cin >> b;
        string s; cin >> s;
        for(ll j = 0; j < b; j++)
            if(s[j] == 'D') v[i] = (v[i] + 1) % 10;
            else v[i] = (v[i] + 9) % 10;
    }
    for(ll i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
