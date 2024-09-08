#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v, f0, f, aux;
ll n, k;

ll cont;

void fun(ll k){
    if(k == 1){
        for(ll i = 0; i < 2 * n; i++) f.push_back(f0[i]);
        return;
    }
    fun(k / 2);
    for(ll i = 0; i < 2 * n; i++)
        if(f[i] == 2 * n) aux.push_back(2 * n);
        else aux.push_back(f[f[i]]);
    if(k % 2)
        for(ll i = 0; i < 2 * n; i++)
            if(aux[i] != 2 * n) aux[i] = f0[aux[i]];
    for(ll i = 0; i < 2 * n; i++)
        f[i] = aux[i];
    aux.clear();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(ll i = 0; i < n; i++){ll a; cin >> a; v.push_back(a);}
    for(ll i = 0; i < n; i++) v.push_back(v[i]);

    ll inicio = 1, fim = n * ll(1e4);

    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;
        ll atual = 0, soma = 0;
        
        for(ll i = 0; i < 2 * n; i++){
            while(soma < meio && atual < 2 * n) soma += v[atual++];
            f0.push_back(atual);
            soma -= v[i];
        }
        
        ll cont_aux = 0;
        fun(k);

        for(ll i = 0; i < n; i++)
            if(f[i] <= i + n) cont_aux++;

        if(cont_aux){
            inicio = meio + 1;
            cont = n - cont_aux;
        }
 
       else fim = meio - 1;
        
        f0.clear(); f.clear();
    }

    cout << inicio - 1 << ' ' << cont << '\n';
}
