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
    ll n, r; cin >> n >> r;
    vll v(n);
    for(auto &vi: v) cin >> vi;
    ll soma = 0, t = 0;
    for(ll i = 0; i < n; i++) soma += (v[i]/2)*2, t += v[i];
    ll resto = t - soma;
    if(resto <= r-soma/2) soma += resto;
    else soma += (r-soma/2) - (resto - (r-soma/2));
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
