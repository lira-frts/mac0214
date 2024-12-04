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
    vpll v(m);
    ll total = 0;
    for(auto &[x, a]: v) cin >> x;
    for(auto &[x, a]: v) cin >> a, total += a;
    if(total != n){
        cout << "-1 \n";
        return;
    }
    sort(all(v));
    ll soma = 0;
    for(ll i = 0; i < m; i++){
        if(soma < v[i].F-1){
            cout << "-1 \n";
            return;
        }
        soma += v[i].S;
    }
    ll resp = n*(n+1)/2;
    for(ll i = 0; i < m; i++) resp -= v[i].F*v[i].S;
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
