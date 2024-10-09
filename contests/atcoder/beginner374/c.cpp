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
    ll n; cin >> n;
    vll v(n);
    ll t = 0;
    for(ll &vi: v) cin >> vi, t += vi;
    ll minimo = 1e15;
    for(ll i = 0; i < (1 << n); i++){
        ll soma = 0;
        for(ll j = 0; j < n; j++)
            if(i >> j & 1) soma += v[j];
        minimo = min(minimo, max(soma, t-soma));
    } 
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
