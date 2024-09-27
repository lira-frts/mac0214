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
    sort(v.begin(), v.end());
    ll soma = 0, inicio = 0, fim = n-1;
    while(inicio < fim) soma += v[fim--] - v[inicio++];
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
