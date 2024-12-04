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
    ll q; cin >> q;
    vll v;
    ll inicio = 0, tempo = 0;
    while(q--){
        ll op; cin >> op;
        if(op == 1) v.pb(tempo);
        if(op == 2){
            ll t; cin >> t; tempo += t;
        }
        if(op == 3){
            ll h; cin >> h;
            ll x = 0;
            for(ll i = inicio; i < v.size(); i++){
                if(tempo - v[i] >= h) x++;
                else break;
            }
            inicio += x;
            cout << x << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
