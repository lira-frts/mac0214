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

string s;

vll dfs(ll v, vvll &E){
    vll resp(3);
    for(ll u: E[v]){
        vll aux = dfs(u, E);
        resp[0] += aux[0], resp[1] += aux[1], resp[2] += aux[2];
    }
    if(s[v] == 'B') resp[0] += 1;
    else resp[1] += 1;
    if(resp[0] == resp[1]) resp[2] += 1;
    return resp;
}

void solve(){
    ll n; cin >> n;
    vvll E(n);
    for(ll i = 1; i < n; i++){
        ll x; cin >> x;
        E[--x].pb(i);
    }
    cin >> s;
    cout << dfs(0, E)[2] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
