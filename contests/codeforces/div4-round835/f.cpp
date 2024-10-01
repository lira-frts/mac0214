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
    ll n, c, d; cin >> n >> c >> d;
    vll v(n);
    for(ll &vi: v) cin >> vi;
    sort(v.begin(), v.end());
   
    ll soma_maxima = 0;
    for(ll i = 0; i < n; i++) soma_maxima += v[i];
 
    ll inicio = 0, fim = d-1;
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2;
        ll soma = 0;

        ll resto = d % (meio + 1);
   
        for(ll i = 0; n-1-i >= 0 && i < meio+1; i++){
            soma += v[n-1-i] * (d / (meio + 1));
            if(resto) soma += v[n-1-i], resto--;
        }

        if(soma >= c) inicio = meio + 1;
        else fim = meio - 1;
    }

    if(fim == -1) cout << "Impossible\n";
    else if(inicio == d) cout << "Infinity\n";
    else cout << fim << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
