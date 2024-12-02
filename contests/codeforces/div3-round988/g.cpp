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

const ll MOD = 998244353;

vll divisores(ll a){
    vll div; 
    for(ll i = 2; i * i <= a; i++){
        if(a % i == 0) div.pb(i);
        while(a % i == 0) a /= i;
    }
    if(a != 1) div.pb(a);
    return div;
}

void solve(){
    ll n; cin >> n;
    vll pd(ll(1e6)+1); 
    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        vll div = divisores(a); ll qtd_div = div.size();
        ll cont = 0;
        for(ll bits = 1; bits < (1<<qtd_div); bits++){
            ll sinal = __builtin_popcount(bits) % 2 == 0 ? -1 : 1;
            ll num = 1;
            for(ll bit = 0; bit < qtd_div; bit++)
                if(1 << bit & bits) num *= div[bit];
            cont = (cont + sinal * pd[num] + MOD) % MOD;
        }
        if(i == 0) cont = 1;
        for(ll bits = 0; bits < (1<<qtd_div); bits++){
            ll num = 1;
            for(ll bit = 0; bit < qtd_div; bit++)
                if(1 << bit & bits) num *= div[bit];
            pd[num] += cont, pd[num] %= MOD;
        }
        if(i == n-1) cout << cont << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
