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
    string s; cin >> s;
    vll v(26, 0);
    for(ll i = 0; i < n; i++) v[s[i] - 'A']++;
    ll soma = 0;
    for(ll i = 0; i < 26; i++)
        if(v[i]) soma += (v[i] + 1);
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
