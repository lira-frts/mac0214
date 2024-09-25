/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpll = vector<pll>;
using vlll = vector<lll>;
using vvpll = vector<vpll>;

void solve(){
    ll n, k; cin >> n >> k;
    vll v(n), acc(n+1, 0);
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 1; i <= n; i++) acc[i] += acc[i-1] + v[i-1];
    ll maximo = 0;
    for(ll i = 0; i <= n; i++){
        // até o i-ésimo, comprou chave
        ll val = acc[i] - i * k;
        // depois do i-ésimo bau, só vai dividir por 2 (no maximo 30 vezes)
        for(ll delta = 1; delta <= min(30LL, n - i); delta++)
            val += v[i - 1 + delta] / (ll) pow(2, delta);
        maximo = max(maximo, val);
    }
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
