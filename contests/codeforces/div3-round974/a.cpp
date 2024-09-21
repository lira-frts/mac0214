/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    ll cont = 0, total = 0;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x == 0 && total > 0) cont++, total--;
        if(x >= k) total += x;
    }
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
