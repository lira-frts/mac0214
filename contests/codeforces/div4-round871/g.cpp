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

vvll mat(1500, vll(1500));
vll resp = {0};

void fun(){
    ll x = 1;
    for(ll i = 1; i < 1500; i++)
        for(ll j = i; j >= 1; j--)
            mat[j][i-j+1] = mat[j-1][i-j+1] + mat[j][i-j] - mat[j-1][i-j] + x*x, resp.pb(mat[j][i-j+1]), x++;
}

void solve(){
    ll n; cin >> n;
    cout << resp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fun();
    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
