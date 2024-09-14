#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;

    bool eg[n][n], eh[n][n];

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            eg[i][j] = eh[i][j] = 0; 
    
    ll mg; cin >> mg;
    for(ll i = 0; i < mg; i++){
        ll u, v; cin >> u >> v; u--, v--;
        eg[u][v] = 1, eg[v][u] = 1;
    }

    ll mh; cin >> mh;
    for(ll i = 0; i < mh; i++){
        ll u, v; cin >> u >> v; u--, v--;
        eh[u][v] = 1, eh[v][u] = 1;
    }

    ll mat[n][n];

    for(ll i = 0; i < n; i++)
        for(ll j = i + 1; j < n; j++)
            cin >> mat[i][j];

    vector<ll> v(n);
    for(ll i = 0; i < n; i++) v[i] = i;

    ll minimo = INF;

    do{
        ll soma = 0;
        for(ll i = 0; i < n; i++)
            for(ll j = i + 1; j < n; j++)
                if(eh[i][j] != eg[v[i]][v[j]]) soma += mat[i][j];
        minimo = min(minimo, soma);
    }
    while(next_permutation(v.begin(), v.end()));

    cout << minimo << '\n';
}
