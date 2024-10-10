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
    map<ll, ll> h, v, ip, in;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        h[y] += 1, v[x] += 1, ip[x+y] += 1, in[x-y] += 1;
    }
    ll soma = 0;
    for(auto &[x, cont]: h) soma += cont * (cont - 1);
    for(auto &[x, cont]: v) soma += cont * (cont - 1);
    for(auto &[x, cont]: ip) soma += cont * (cont - 1);
    for(auto &[x, cont]: in) soma += cont * (cont - 1);
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
