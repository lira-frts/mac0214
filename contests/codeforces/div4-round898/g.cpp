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
    string s; cin >> s; ll n = s.size();
    bool bb = (s.find("BB") != -1 ? 1 : 0);
    ll as = count(all(s), 'A');
    ll minimo = 1e9, ultima_pos = 0;
    for(ll i = 0; i < n; i++)
        if(s[i] != 'A') minimo = min(minimo, i-ultima_pos), ultima_pos = i+1;
    minimo = min(minimo, n-ultima_pos);
    cout << (s[0] == 'B' || s[n-1] == 'B' || bb ? as : as - minimo) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
