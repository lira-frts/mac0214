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
    string s; cin >> s; s += "aaa";
    ll cont = 0;
    for(ll i = 0; i < s.size(); i++)
        if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') cont++; 
    ll q; cin >> q;
    while(q--){
        ll x; cin >> x; x--;
        for(ll i = x-3; i <= x; i++)
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') cont--; 
        cin >> s[x];
        for(ll i = x-3; i <= x; i++)
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') cont++; 
        cout << (cont > 0 ? "yes\n" : "no\n");
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
