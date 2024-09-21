/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 2e5;

vector<ll> v(N);
ll n;

ll pd(ll h, ll pos, ll qtd2, ll qtd3){
    if(pos >= n) return 0;
    if(h > v[pos]) return 1 + pd(h+v[pos]/2, pos+1, qtd2, qtd3);
    ll m2 = 0, m3 = 0;
    if(qtd2 > 0) m2 = pd(2*h, pos, qtd2-1, qtd3);
    if(qtd3 > 0) m3 = pd(3*h, pos, qtd2, qtd3-1);
    return max(m2, m3);
}

void solve(){
    ll h; cin >> n >> h;
    for(ll i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.begin() + n);
    cout << pd(h, 0, 2, 1) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
