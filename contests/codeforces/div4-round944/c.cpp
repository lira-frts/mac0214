/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);

    bool flag_c = 0, flag_d = 0;
    for(ll i = a; i <= b; i++){
        if(i == c) flag_c = 1;
        if(i == d) flag_d = 1;
    }

    cout << (flag_c == flag_d ? "NO\n" : "YES\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
