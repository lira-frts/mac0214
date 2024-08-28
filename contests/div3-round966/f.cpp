#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mat[101][101][101];
ll minimo[1001][101];

const ll INF = 123456789;
const ll KMAX = 100;

ll cont = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    ll cont = 0;
    while(t--){
        ll n, k; cin >> n >> k;
        for(ll i = 0; i <= n; i++) for(ll j = 0; j <= k; j++) minimo[i][j] = INF; 
        for(ll i = 1; i <= n; i++){
            ll a, b; cin >> a >> b;
            ll menor = min(a, b), maior = max(a, b);
            for(ll i = 100; i > a + b; i--) mat[a][b][i] = INF;
            for(ll i = 0; i <= maior - menor; i++) mat[a][b][i] = menor * i;
            ll menor_atual = menor, par = 1;
            for(ll i = maior - menor + 1; i <= min(a + b, KMAX); i++){
                cont ++;
                mat[a][b][i] = mat[a][b][i - 1] + menor_atual;
                if(par){menor_atual--; par--;}
                else par++;
            }
            if(i == 1) for(ll j = 0; j <= k; j++) minimo[i][j] = mat[a][b][j];
            else for(ll j = 0; j <= k; j++) for(ll m = 0; m <= j; m++){minimo[i][j] = min(mat[a][b][m] + minimo[i - 1][j - m], minimo[i][j]);}
        }
        cout << (minimo[n][k] == INF ? -1 : minimo[n][k]) << '\n';
    }

    return 0;
}
