#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    ll resp = 0, soma = 0, maximo = 0;
    for(ll i = 0; i < n; i++){
        if(v[i] > maximo){soma += maximo, maximo = v[i];}
        else soma += v[i];
        if(maximo == soma) resp++;
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
