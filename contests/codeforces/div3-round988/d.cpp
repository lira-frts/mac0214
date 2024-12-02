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
    ll n, m, L; cin >> n >> m >> L;
    vvll v(n+m);
    for(ll i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        v[i] = {l, r, 0};
    }
    for(ll i = 0; i < m; i++){
        ll x, val; cin >> x >> val;
        v[n+i] = {x, val, 1};
    }
    sort(all(v));
    multiset<ll> ms;
    ll pula = 0, qtd = 0;
    for(ll i = 0; i < m+n; i++){
        vll v2 = v[i];
        if(v2[2] == 1){
            ms.insert(v2[1]);
            continue;
        }
        ll dist = v2[1] - v2[0];
        while(pula <= dist && !ms.empty()){
            ll x = *ms.rbegin(); ms.erase(ms.find(x));
            pula += x; qtd++;
        }
        if(dist >= pula){
            cout << -1 << '\n';
            return;
        }
    }
    cout << qtd << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
