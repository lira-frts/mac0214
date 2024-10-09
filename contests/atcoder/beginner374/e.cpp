/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){
    ll n, x; cin >> n >> x;
    vvll v(n, vll(4));
    for(auto &vi: v) cin >> vi[0] >> vi[1] >> vi[2] >> vi[3];

    ll inicio = 0, fim = 100*x;
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;
        ll soma = 0;
        for(ll i = 0; i < n; i++){
            ll minimo = 1e12;
            for(ll j = 0; j <= v[i][2]; j++){
                ll falta = max(0LL, meio - j * v[i][0]);
                ll resto = (falta + v[i][2] - 1) / v[i][2];
                ll val = j * v[i][1] + resto * v[i][3];
                minimo = min(minimo, val);
            }
            for(ll j = 0; j <= v[i][0]; j++){
                ll falta = max(0LL, meio - j * v[i][2]);
                ll resto = (falta + v[i][0] - 1) / v[i][0];
                ll val = j * v[i][3] + resto * v[i][1];
                minimo = min(minimo, val);
            }
            soma += minimo;
        }
        if(soma <= x) inicio = meio + 1;
        else fim = meio - 1;
    }
    cout << fim << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
