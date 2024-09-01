#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v(ll(1e5));

void solve(){
    ll a, b; cin >> a >> b;
    ll dif = b - a;
    ll inicio = 0, fim = v.size() - 1, meio;
    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(v[meio] <= dif) inicio = meio + 1;
        else fim = meio - 1;
    }
    cout << inicio << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    v[0] = 0;
    for(ll i = 1; i < v.size(); i++) v[i] = v[i - 1] + i;

    ll t; cin >> t;

    while(t--) solve();
}
