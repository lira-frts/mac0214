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

#define pb push_back
#define all(x) x.begin(),x.end()

ll n, m, minR, maxR, minC, maxC, sz;

const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

void dfs(vvll &g, vvll &vis, ll c, ll r){
    vis[r][c] = 1;
    minR = min(minR, r), maxR = max(maxR, r);
    minC = min(minC, c), maxC = max(maxC, c);
    sz++;
    for(ll i = 0; i < 4; i++){
        ll dc = c + dx[i], dr = r + dy[i];
        if(dc == -1 || dc == m || dr == -1 || dr == n) continue;
        if(g[dr][dc] && !vis[dr][dc]) dfs(g, vis, dc, dr);
    }
}

void solve(){
    cin >> n >> m;

    vvll g(n, vll(m));
    vll FR(n, 0), FC(m, 0);
    for(ll r = 0; r < n; r++)
        for(ll c = 0; c < m; c++){
            char ch; cin >> ch, g[r][c] = (ch == '#');
            if(ch == '.') FR[r]++, FC[c]++;
        }
    
    vvll vis(n, vll(m, 0));
    vll R(n, 0), C(m, 0);
    vvll RC(n, vll(m, 0));

    for(ll r = 0; r < n; r++)
        for(ll c = 0; c < m; c++)
            if(g[r][c] && !vis[r][c]){
                maxR = -1, maxC = -1, minR = 1e9, minC = 1e9, sz = 0;

                dfs(g, vis, c, r);

                minR = max(minR-1, 0LL), minC = max(minC-1, 0LL);
                maxR = min(maxR+1, n-1), maxC = min(maxC+1, m-1);

                R[minR] += sz;
                if(maxR < n-1) R[maxR+1] -= sz;
                C[minC] += sz;
                if(maxC < m-1) C[maxC+1] -= sz;
                
                RC[minR][minC] += sz;
                if(maxR < n-1) RC[maxR+1][minC] -= sz;
                if(maxC < m-1) RC[minR][maxC+1] -= sz;
                if(maxR < n-1 && maxC < m-1) RC[maxR+1][maxC+1] += sz;
            }

    for(ll i = 1; i < n; i++) R[i] += R[i-1];
    for(ll i = 1; i < m; i++) C[i] += C[i-1];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++){
            if(i > 0) RC[i][j] += RC[i-1][j];
            if(j > 0) RC[i][j] += RC[i][j-1];
            if(i > 0 && j > 0) RC[i][j] -= RC[i-1][j-1];
        }

    ll resp = 0;

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            resp = max(resp, (R[i] + C[j] - RC[i][j]) + (FR[i] + FC[j] - (1 - g[i][j])));

    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
