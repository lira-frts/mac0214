#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = ll(1e9+7);

void solve(){
    string s; cin >> s; ll n = s.size();
    vector<ll> v(n), acc(n+1);

    for(ll i = 0; i < n; i++)
        if(s[i] == '0') v[i] = -1;
        else v[i] = 1;

    acc[0] = 0;
    for(ll i = 1; i <= n; i++) acc[i] = acc[i-1] + v[i-1];

    vector<vector<ll>> indices(2*n+1);
    for(ll i = 0; i <= n; i++) indices[n + acc[i]].push_back(i);

    ll resp = 0;
    for(ll i = 0; i <= 2*n; i++){
        if(indices[i].size() <= 1) continue;
        ll soma = (n + 1) * indices[i].size();
        for(ll j = 0; j < indices[i].size(); j++) soma -= indices[i][j];
        for(ll j = 0; j < indices[i].size() - 1; j++){
            ll x = indices[i][j];
            soma -= (n + 1 - x);
            resp = (resp + (x + 1) * soma) % MOD;
        }
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
