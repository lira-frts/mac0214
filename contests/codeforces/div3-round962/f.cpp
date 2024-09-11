#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    ll inicio = 1, fim = ll(1e9);
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;
        ll soma = 0;
        for(ll i = 0; i < n; i++)
            if(a[i] >= meio) soma += (a[i] - meio) / b[i] + 1;

        // no final, fim será o último cara que soma >= k
        if(soma >= k) inicio = meio + 1;
        else fim = meio - 1;
    }

    ll resp = 0, op = 0;

    for(ll i = 0; i < n; i++){
        if(a[i] >= fim){
            ll t = (a[i] - fim) / b[i] + 1;

            // no final, op será >= k
            op += t;

            ll ultimo = a[i] - b[i] * (t - 1);
            resp += (a[i] + ultimo) * t / 2;
        }
    }

    // como foram realizadas (op - k) operações a mais na hora de contar resp
    // (e cada uma dessas operações vale fim), devemos subtrair fim * (op - k)

    cout << resp - fim * (op - k) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
