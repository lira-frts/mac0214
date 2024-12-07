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
    for(ll i = 0; i < n; i++){
        ll d1 = s[i] - '0';
        ll pos, flag = 0, melhor = -1;
        for(ll j = i+1; j < min(i+10, n); j++){
            ll d2 = s[j] - '0';
            if(d2 == 0 || d2 - d1 <= j - i) continue;
            ll d3 = d2 - (j - i);
            if(d3 > melhor) pos = j, flag = 1, melhor = d3;
        }
        if(flag){
            for(ll j = pos; j > i; j--) swap(s[j], s[j-1]);
            s[i] -= (pos-i);
        }
    }
    cout << s << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
