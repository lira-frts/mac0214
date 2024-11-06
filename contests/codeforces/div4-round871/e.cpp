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

ll n, m, cont;

vll dx = {1, 0, -1, 0};
vll dy = {0, 1, 0, -1};

void dfs(vvll &mat, vvll &vis, ll x, ll y){
    vis[y][x] = 1;
    cont += mat[y][x];
    for(ll i = 0; i < 4; i++){
        ll x2 = x + dx[i], y2 = y + dy[i];
        if(x2 < 0 || x2 == m || y2 < 0 || y2 == n || vis[y2][x2] || mat[y2][x2] == 0) continue;
        dfs(mat, vis, x2, y2);
    }
}

void solve(){
    cin >> n >> m;
    vvll mat(n, vll(m));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) cin >> mat[i][j];
    vvll vis(n, vll(m, 0));
    ll maximo = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(!vis[i][j] && mat[i][j] != 0){
                cont = 0;
                dfs(mat, vis, j, i);
                maximo = max(maximo, cont);
            }
    cout << maximo << '\n'; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
