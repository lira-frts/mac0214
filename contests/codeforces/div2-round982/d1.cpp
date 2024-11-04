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

const ll INF = 1e18;

ll n, m;

ll fun(vvll &pd, ll inicio, ll k, vll &acc, vll &b){
    if(inicio > n) return 0;
    if(k > m) return INF;
    if(pd[inicio][k] != -1) return pd[inicio][k];
    ll prox = upper_bound(acc.begin(), acc.end(), b[k-1]+acc[inicio-1]) - acc.begin();
    if(inicio == prox) return pd[inicio][k] = INF;
    ll type1 = fun(pd, inicio, k+1, acc, b);
    ll type2 = fun(pd, prox, k, acc, b) + m-k;
    return pd[inicio][k] = min(type1, type2);
}

void solve(){
    cin >> n >> m;
    vll a(n), b(m);
    for(ll &ai: a) cin >> ai;
    for(ll &bi: b) cin >> bi;
    vll acc(n+1, 0);
    for(ll i = 1; i <= n; i++) acc[i] = acc[i-1] + a[i-1];
    vvll pd(n+1, vll(m+1, -1));
    ll x = fun(pd, 1, 1, acc, b);

    if(x == INF) cout << -1 << endl;
//    cout << (x == INF ? -1 : x) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
