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

const ll INF = 1e18;

void solve(){
    ll n; cin >> n;
    ll min1 = INF, min2 = INF, min3 = INF; 
    for(ll i = 0; i < n; i++){
        ll x; string s; cin >> x >> s;
        if(s[0] == '1') min1 = min(min1, x);
        if(s[1] == '1') min2 = min(min2, x);
        if(s == "11") min3 = min(min3, x);
    }
    if(min1 == INF || min2 == INF) cout << -1 << '\n';
    else cout << min(min1 + min2, min3) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
