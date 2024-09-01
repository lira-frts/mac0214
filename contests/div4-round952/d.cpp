#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, m; cin >> n >> m;
    ll mat[n][m];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++){char c; cin >> c; if(c == '.') mat[i][j] = 0; else mat[i][j] = 1;}
    ll esq = -1, dir, cima = -1, baixo;
    for(ll i = 0; i < n; i++){
        ll soma = 0;
        for(ll j = 0; j < m; j++) soma += mat[i][j];
        if(soma == 1 && esq == -1){esq = i, dir = i;}
        else if(soma == 1 && esq != -1) dir = i;
    }
    for(ll j = 0; j < m; j++){
        ll soma = 0;
        for(ll i = 0; i < n; i++) soma += mat[i][j];
        if(soma == 1 && cima == -1){cima = j, baixo = j;}
        else if(soma == 1 && cima != -1) baixo = j;
    }
    cout << (dir + esq) / 2 + 1 << ' ' << (cima + baixo) / 2 + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
