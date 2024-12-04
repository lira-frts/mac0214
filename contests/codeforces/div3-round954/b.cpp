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

vll di = {0, 0, -1, 1};
vll dj = {1, -1, 0, 0};

void solve(){
    ll n, m; cin >> n >> m;
    vvll mat(n, vll(m));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) cin >> mat[i][j];
    for(ll j = 0; j < m; j++)
        for(ll i = 0; i < n; i++){
            ll flag = 1, maximo = 0;
            for(ll k = 0; k < 4; k++){
                ll i2 = i + di[k], j2 = j + dj[k];
                if(i2 == -1 || i2 == n || j2 == -1 || j2 == m) continue;
                if(mat[i2][j2] >= mat[i][j]) flag = 0;
                maximo = max(maximo, mat[i2][j2]);
            }
            if(flag) mat[i][j] = maximo;
        }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++) cout << mat[i][j] << ' '; cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
