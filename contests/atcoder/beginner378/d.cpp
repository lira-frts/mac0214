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

ll cont = 0;

vll dx = {-1, 0, 0, 1};
vll dy = {0, -1, 1, 0};

ll h, w, k;

void dfs(vvll &mat, vvll &vis, ll x, ll y, ll mov){
    vis[y][x] = 1;
    if(mov == k){
        cont++;
        vis[y][x] = 0;
        return;
    }
    for(ll i = 0; i < 4; i++){
        ll x2 = x + dx[i], y2 = y + dy[i];
        if(x2 < 0 || x2 == w || y2 < 0 || y2 == h || vis[y2][x2] || !mat[y2][x2]) continue;
        dfs(mat, vis, x2, y2, mov+1);
    }
    vis[y][x] = 0;
}

void solve(){
    cin >> h >> w >> k;
    vvll mat(h, vll(w));
    for(ll i = 0; i < h; i++)
        for(ll j = 0; j < w; j++){
            char c; cin >> c;
            mat[i][j] = (c == '.');
        }
    vvll vis(h, vll(w, 0));
    for(ll i = 0; i < h; i++)
        for(ll j = 0; j < w; j++){
            if(!mat[i][j]) continue;
            dfs(mat, vis, j, i, 0);
        }
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
