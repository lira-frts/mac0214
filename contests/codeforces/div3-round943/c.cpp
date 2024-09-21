/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    vector<ll> x(n-1), a(n), q(n);
    for(ll i = 0; i < n-1; i++) cin >> x[i];
    a[0] = x[0]+1;
    for(ll i = 1; i < n-1; i++){
        q[i-1] = ((x[i] + 1 - x[i-1]) + a[i-1] - 1) / a[i-1];
        a[i] = a[i-1]*q[i-1]+x[i-1];
    }
    a[n-1] = a[n-2] + x[n-2];
    for(ll i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
