/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, d, k; cin >> n >> d >> k;
    vector<ll> inicio(n+1, 0), fim(n+1, 0);
    for(ll i = 0; i < k; i++){
        ll l, r; cin >> l >> r;
        inicio[l]++, fim[r]++;
    }
    for(ll i = 1; i <= n; i++) inicio[i] += inicio[i-1], fim[i] += fim[i-1];
    ll mae = 1e9, irmao = -1, ind_mae, ind_irmao;
    for(ll i = d; i <= n; i++){
        ll total = inicio[i] - fim[i-d];
        if(total < mae) mae = total, ind_mae = i-d+1;
        if(total > irmao) irmao = total, ind_irmao = i-d+1;
    }
    cout << ind_irmao << ' ' << ind_mae << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
