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
    string s; cin >> s;
    vvll v(26);
    for(ll i = 0; i < s.size(); i++) v[s[i] - 'A'].pb(i);
    ll soma = 0;
    for(ll i = 0; i < 26; i++){
        ll sz = v[i].size();
        for(ll j = 0; j < sz; j++)
            soma += ((v[i][j] - 1) * j - v[i][j] * (sz-1-j));
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
