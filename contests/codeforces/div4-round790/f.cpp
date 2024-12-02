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
    ll n, k; cin >> n >> k;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x; mp[x]++;
    }
    vll v;
    for(auto &[key, value]: mp) 
        if(value >= k) v.pb(key);
    if(v.size() == 0){
        cout << -1 << '\n';
        return;
    }
    ll l = v[0], r = v[0], lresp = v[0], rresp = v[0];
    for(ll i = 0; i < v.size()-1; i++){
        if(v[i] + 1 != v[i+1]){
            if(r - l > rresp - lresp) lresp = l, rresp = r;
            l = v[i+1];
        }
        r = v[i+1];
    }
    if(r - l > rresp - lresp) lresp = l, rresp = r;
    cout << lresp << ' ' << rresp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
