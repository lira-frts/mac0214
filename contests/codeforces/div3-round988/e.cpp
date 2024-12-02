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
    ll n; cin >> n;
    vll xs(n);
    string s;
    bool flag = 0;
    for(ll i = 1; i < n; i++){
        cout << "? 1 " << i+1 << '\n';
        cout.flush();
        ll x; cin >> x; xs[i] = x;
        if(x != 0){
            if(!flag){
                flag = 1;
                for(ll j = 0; j < i-x; j++) s.pb('1');
                for(ll j = i-x; j < i; j++) s.pb('0');
                s.pb('1');
            }
            else{
                if(xs[i] == xs[i-1]) s.pb('0');
                else s.pb('1');
            }
        }
    }
    if(flag) cout << "! " << s << '\n';
    else cout << "! IMPOSSIBLE\n";
    cout.flush();
}

int main(){
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
