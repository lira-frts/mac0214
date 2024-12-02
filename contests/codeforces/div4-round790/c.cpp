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
    ll n, m; cin >> n >> m;
    vector<string> v(n);
    for(string &vi: v) cin >> vi;
    ll minimo = 1e18;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            ll soma = 0;
            for(ll k = 0; k < m; k++) soma += abs(v[i][k]-v[j][k]);
            minimo = min(minimo, soma);
        }
    }
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
