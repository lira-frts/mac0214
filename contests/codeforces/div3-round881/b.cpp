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

void solve(){
    ll n; cin >> n;
    vll v(n);
    for(ll &x: v) cin >> x;
    ll qtd = 0, intervalos = 0, soma = 0;
    for(ll i = 0; i < n; i++){
        if(v[i] > 0){
            if(qtd) intervalos++;
            qtd = 0;
        }
        if(v[i] < 0) v[i] = -v[i], qtd++;
        soma += v[i];
    }
    if(qtd) intervalos++;
    cout << soma << ' ' << intervalos << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
