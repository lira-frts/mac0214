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

const ll MOD = 1e9+7;

void solve(){
    ll n, k; cin >> n >> k;
    vll pd(64);
    for(ll i = 0; i < n; i++){
        vll pd2 = pd;
        ll x; cin >> x;
        for(ll j = 0; j < 64; j++) pd2[x&j] = (pd2[x&j] + pd[j]) % MOD;
        pd2[x] = (pd2[x] + 1) % MOD;
        pd = pd2;
    }
    ll resp = 0;
    for(ll i = 0; i < 64; i++)
        if(__builtin_popcount(i) == k) resp = (resp + pd[i]) % MOD;
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
