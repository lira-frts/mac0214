/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> a(k), b(k);

    for(ll i = 0; i < k; i++) cin >> a[i];
    for(ll i = 0; i < k; i++) cin >> b[i];

    while(q--){
        ll d; cin >> d;
        auto lower = lower_bound(a.begin(), a.end(), d);
        ll ind = lower - a.begin();
        if(ind == 0) cout << b[0] * d / a[0] << ' '; 
        else cout << b[ind-1] + ((b[ind] - b[ind - 1]) * (d - a[ind-1])) / (a[ind] - a[ind - 1]) << ' '; 
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
