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
    vll v(n), acc(n+1);
    for(ll i = 0; i < n; i++) cin >> v[i], acc[i+1] = (acc[i] + v[i]) % m;
    ll resp = 0, s = 0;
    ordered_set<pll> os; os.insert({0, 0});
    for(ll i = 1; i <= n; i++){
        ll xr = os.size() - os.order_of_key({acc[i], i});
        resp += (acc[i] * i - s + m * xr);
        s += acc[i];
        os.insert({acc[i], i});
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
