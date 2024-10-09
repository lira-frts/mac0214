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
    ll n, w; cin >> n >> w;
    vpll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    vvll dp(w+1, vll(w+1, 0)), f(w+1, vll(w+1, 0));

    // f[i][j] := maior valor que você consegue pegando exatamente j caras com preço = i
    for(ll i = 1; i <= w; i++){
        multiset<ll> ms;
        for(ll j = 0; j < n; j++)
            if(v[j].first == i) ms.insert(v[j].second - 1);
        if(ms.empty()) continue;
        for(ll j = 1; j <= w; j++){
            ll maximo = *ms.rbegin(); ms.erase(ms.find(maximo));
            f[i][j] = f[i][j-1] + maximo;
            ms.insert(maximo - 2);
        }
    }   

    // dp[i][j] := maior felicidade que consegue pegando caras com peso <= i e peso total <= j
    for(ll i = 1; i <= w; i++)
        for(ll j = 0; j <= w; j++)
            for(ll k = 0; k <= j/i; k++)
                dp[i][j] = max(dp[i][j], dp[i-1][j-i*k] + f[i][k]);

    cout << dp[w][w] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
