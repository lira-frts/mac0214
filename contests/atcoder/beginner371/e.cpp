#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> ocorrencias(n+1);

    for(ll i = 0; i < n; i++) cin >> v[i];

    for(ll i = 0; i < n; i++) ocorrencias[v[i]].push_back(i+1);
    for(ll i = 1; i <= n; i++) ocorrencias[i].push_back(n+1);

    ll resp = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < ocorrencias[i].size() - 1; j++){
            ll x1 = ocorrencias[i][j];
            ll x2 = ocorrencias[i][j + 1];
            resp += (x2 - x1) * x1;
        }
    }

    cout << resp << '\n';
}
