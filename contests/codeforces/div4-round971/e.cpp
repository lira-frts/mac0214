#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    ll inicio = 0, fim = n - 1;
    ll soma_total = (2 * k + n - 1) * n / 2;
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;
        ll soma_meio = (2 * k + meio) * (meio + 1) / 2;
        ll soma_depois = soma_total - soma_meio;
        if(soma_meio - soma_depois >= 0) fim = meio - 1;
        else inicio = meio + 1;
    }
    ll soma_fim = (2 * k + fim) * (fim + 1) / 2;
    ll soma_depois_fim = soma_total - soma_fim;
    ll soma_inicio = (2 * k + inicio) * (inicio + 1) / 2;
    ll soma_depois_inicio = soma_total - soma_inicio;
    cout << min(abs(soma_fim - soma_depois_fim), abs(soma_inicio - soma_depois_inicio)) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
