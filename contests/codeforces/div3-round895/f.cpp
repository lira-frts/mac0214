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

ll minimo, ind;

void dfs(vll &vis, vll &c, vll &a, ll v){
    vis[v] = 1;
    if(c[v] < minimo) minimo = c[v], ind = v;
    if(!vis[a[v]]) dfs(vis, c, a, a[v]);
}

void solve(){
    ll n; cin >> n;
    vll a(n), c(n);
    for(auto &ai: a) cin >> ai, ai--;
    for(auto &ci: c) cin >> ci;
    vll v(n, 0);
    set<pll> st;
    for(ll i = 0; i < n; i++) v[a[i]]++;
    for(ll i = 0; i < n; i++) st.insert({v[i], i});
    vll resp, vis(n);
    while(1){
        auto[in, vtx] = *st.begin();
        if(in != 0) break;
        st.erase({in, vtx});
        st.erase({v[a[vtx]], a[vtx]});
        resp.pb(vtx+1);
        vis[vtx] = 1;
        v[a[vtx]]--;
        st.insert({v[a[vtx]], a[vtx]});
    }
    for(ll i = 0; i < n; i++)
        if(!vis[i]){
            minimo = 1e18;
            dfs(vis, c, a, i);
            ll ind_atual = a[ind];
            while(ind_atual != ind){
                resp.pb(ind_atual+1);
                ind_atual = a[ind_atual];
            }
            resp.pb(ind+1);
        }
    for(ll vi: resp) cout << vi << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
