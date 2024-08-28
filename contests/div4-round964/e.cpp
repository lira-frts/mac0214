#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll acumulado[200001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    acumulado[0] = 0;

    for(ll i = 1; i <= 2e5; i++){
        ll aux = 0;
        for(ll j = i; j != 0; j /= 3) aux++;
        acumulado[i] = acumulado[i - 1] + aux;
    }

    while(t--){
        ll a, b; cin >> a >> b;
        ll soma = 2 * (acumulado[a] - acumulado[a - 1]) + acumulado[b] - acumulado[a];     
        cout << soma << '\n';
    }

    return 0;
}
