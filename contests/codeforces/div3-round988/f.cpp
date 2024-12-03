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
#define rall(a) a.rbegin(), a.rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vll h(n), pos(n);
    for(ll &hi: h) cin >> hi;
    for(ll &p: pos) cin >> p;
    ll inicio = 1, fim = 1e9;
    while(inicio <= fim){
        ll meio = (inicio + fim) / 2; 
        bool flag = 0;
        vpll v;
        for(ll i = 0; i < n; i++){
            ll x = (h[i]+meio-1)/meio;
            if(x > m) continue;
            ll delta = m - x;
            v.pb({pos[i]-delta, 0}), v.pb({pos[i]+delta, 1});
        }
        sort(all(v));
        ll cont = 0;
        for(ll i = 0; i < v.size(); i++){
            if(v[i].S == 0) cont++;
            else cont--;
            if(cont >= k) flag = 1;
        }
        if(flag) fim = meio - 1;
        else inicio = meio + 1;
    }
    cout << (inicio == 1e9+1 ? -1 : inicio) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
