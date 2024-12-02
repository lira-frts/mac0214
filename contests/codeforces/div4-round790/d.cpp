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
    vvll v(n, vll(m));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) cin >> v[i][j];
    ll maximo = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll soma = v[i][j];
            for(ll k = 1; i-k >= 0 && j-k >= 0; k++) soma += v[i-k][j-k]; 
            for(ll k = 1; i-k >= 0 && j+k < m; k++) soma += v[i-k][j+k]; 
            for(ll k = 1; i+k < n && j-k >= 0; k++) soma += v[i+k][j-k]; 
            for(ll k = 1; i+k < n && j+k < m; k++) soma += v[i+k][j+k]; 
            maximo = max(maximo, soma);
        }
    }
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
