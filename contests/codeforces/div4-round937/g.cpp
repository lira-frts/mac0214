/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;

    map<string, ll> aux;
    vector<pair<ll, ll>> musicas(n);

    ll cont = 1;
    for(ll i = 0; i < n; i++){
        string s, t; cin >> s >> t;
        if(aux.find(s) == aux.end()) aux[s] = cont++;
        if(aux.find(t) == aux.end()) aux[t] = cont++;
        musicas[i] = {aux[s], aux[t]};
    } 

    // dp[i][j] possível chegar no estado i sendo j a última música
    bool dp[1<<n][n];
    
    for(ll mask = 0; mask < 1<<n; mask++)
        for(ll i = 0; i < n; i++)
            dp[mask][i] = 0;

    for(ll i = 0; i < n; i++) dp[1 << i][i] = 1;

    // os bits setados são as músicas que estão presentes
    for(ll mask = 0; mask < 1<<n; mask++){
        for(ll i = 0; i < n; i++){
            if(!dp[mask][i]) continue;
            for(ll j = 0; j < n; j++){
                if(mask >> j & 1) continue;
                if(musicas[i].first == musicas[j].first || musicas[i].second == musicas[j].second){
                    dp[mask | (1 << j)][j] = 1;
                }
            }
        }
    }

    ll maximo = 0;
    for(ll mask = 0; mask < 1<<n; mask++){
        bool flag = 0;
        ll soma = 0;
        for(ll i = 0; i < n; i++){
            soma += (mask >> i & 1);
            if(dp[mask][i]) flag = 1;
        }
        if(flag) maximo = max(maximo, soma);
    }
    cout << n - maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
