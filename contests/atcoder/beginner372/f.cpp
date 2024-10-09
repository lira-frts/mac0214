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

const ll MOD = 998244353;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vpll E(m);
    for(auto &[u, v]: E) cin >> u >> v;
    vll dp(n+1+k); dp[1+k] = 1;
    // o "verdadeiro" dp[1 .. n] está em dp[1+i .. n+i]
    for(ll i = k; i > 0; i--){
        vpll somas;
        // para o vértice v, vamos somar quanto tem no "verdadeiro" vértice u
        for(auto [u, v]: E) somas.pb({v, dp[u+i]});
        // ao mover todo mundo para a esquerda, o único "novo" é o i
        dp[i] = dp[n+i];
        // agora que todo mundo foi para a esquerda, podemos somar o que tinhamos
        // calculado (o novo "verdadeiro" do vértice u é u-1+i)
        for(auto [u, val]: somas) dp[u-1+i] = (dp[u-1+i] + val) % MOD;
    }
    ll soma = 0;
    for(ll i = 1; i <= n; i++) soma = (soma + dp[i]) % MOD;
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
