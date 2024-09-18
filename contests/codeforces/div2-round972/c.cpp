/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = ll(1e9);
const string narek = "narek";

void solve(){
    ll n, m; cin >> n >> m;

    // dp[i] é o máximo de pontos que dá pra fazer com a última letra sendo narek[(i-1)%5]
    vector<ll> dp(5, -INF), aux;
    dp[0] = 0;    

    for(ll i = 0; i < n; i++){
        aux = dp;
        string s; cin >> s;
        for(ll j = 0; j < 5; j++){
            ll pontos = 0, atual = j;
            for(ll k = 0; k < m; k++){
                ll pos = narek.find(s[k]);
                if(pos == -1) continue;
                if(pos == atual){
                    atual = (atual + 1) % 5;
                    pontos++;
                }
                else pontos--;
            }
            dp[atual] = max(dp[atual], aux[j] + pontos);
        }
    }

    ll resp = 0;
    for(ll i = 0; i < 5; i++) resp = max(resp, dp[i] - 2 * i);
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
