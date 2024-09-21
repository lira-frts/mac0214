/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, d, k; cin >> n >> d >> k;
    vector<vector<ll>> inicio(n+1), fim(n+1);
    for(ll i = 0; i < k; i++){
        ll l, r; cin >> l >> r;
        inicio[l].push_back(i);
        fim[r].push_back(i);
    }
    set<ll> s;
    for(ll i = 1; i <= d; i++)
        for(ll j = 0; j < inicio[i].size(); j++) s.insert(inicio[i][j]);
    ll mae = s.size(), irmao = s.size(), ind_mae = 1, ind_irmao = 1;
    for(ll i = d+1; i <= n; i++){
        for(ll j = 0; j < inicio[i].size(); j++) s.insert(inicio[i][j]);
        for(ll j = 0; j < fim[i-d].size(); j++) s.erase(fim[i-d][j]);
        if(s.size() < mae) mae = s.size(), ind_mae = i-d+1;
        if(s.size() > irmao) irmao = s.size(), ind_irmao = i-d+1;
    }
    cout << ind_irmao << ' ' << ind_mae << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
