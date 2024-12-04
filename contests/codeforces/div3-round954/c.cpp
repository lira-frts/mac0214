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
    string s; cin >> s;
    set<ll> me_matar;
    for(ll i = 0; i < m; i++){
        ll x; cin >> x; x--;
        me_matar.insert(x);
    }
    vector<char> c(m);
    for(char &ci: c) cin >> ci;
    sort(all(c));
    ll ind = 0;
    for(ll x: me_matar) s[x] = c[ind++];
    cout << s << '\n';
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
