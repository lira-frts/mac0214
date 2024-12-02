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
    ll k; cin >> k;
    map<ll, ll> mp;
    for(ll i = 0; i < k; i++){
        ll x; cin >> x;
        mp[x] += 1;
    }
    ll flag = 0;
    for(ll i = 1; i <= sqrt(k-2); i++){
        if((k-2) % i != 0) continue;
        if(mp.find(i) == mp.end()) continue;
        ll j = (k-2) / i;
        if(j == i){
            if(mp[i] != 1) flag = 1;
        }
        else
            if(mp.find(j) != mp.end()) flag = 1;
        if(flag){
            cout << i << ' ' << j << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
