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
    string s; cin >> s;
    bool f0 = 0, f1 = 0, f2 = 0;
    if(s[0] == 'Y' || s[0] == 'y') f0 = 1;
    if(s[1] == 'E' || s[1] == 'e') f1 = 1;
    if(s[2] == 'S' || s[2] == 's') f2 = 1;
    if(f0 && f1 && f2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
