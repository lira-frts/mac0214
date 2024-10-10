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
    ll n, k; cin >> n >> k;
    vll v(n);
    for(auto &vi: v) cin >> vi;
    sort(all(v));
    ll maximo = 1, qtd = 1;
    for(ll i = 0; i < n-1; i++){
        if(v[i+1] - v[i] <= k) qtd++;
        else qtd = 1;
        maximo = max(maximo, qtd);
    }
    cout << n - maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
