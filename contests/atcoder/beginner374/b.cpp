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
    string s, t; cin >> s >> t; ll n = s.size(), m = t.size();
    for(ll i = 0; i < max(n, m); i++){
        if(i >= min(n, m) || s[i] != t[i]){ 
            cout << i+1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
