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

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){
    ll n; cin >> n;
    ll mat[n][n];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) cin >> mat[i][j];
    ll soma = 0;
    for(ll i = 1; i <= n; i++){
        ll minimo = 1e9;
        for(ll j = 0; j < i; j++) minimo = min(minimo, mat[j][n-(i-j)]);
        if(minimo < 0) soma += -minimo;
        minimo = 1e9;
        if(i != n){
            for(ll j = 0; j < i; j++) minimo = min(minimo, mat[n-(i-j)][j]);
            if(minimo < 0) soma += -minimo;
        }
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
