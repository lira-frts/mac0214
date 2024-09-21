/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    ll soma = 0;
    for(ll i = 0; i < n; i++){
        cin >> v[i]; soma += v[i];
    }
    sort(v.begin(), v.end());
    if(n <= 2){
        cout << -1 << '\n';
        return;
    }

    ll val = v[n/2] * 2 * n - soma + 1;
    cout << max(0LL, val) << '\n';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
