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

const ll N = 2e5+1;

vll parent(N), sz(N);
vvll vtx(N);

void make_set(ll v){
    parent[v] = v;
    vtx[v].pb(v);
}
 
ll find_set(ll v){
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets(ll u, ll v){
    u = find_set(u), v = find_set(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];

    // parte que guarda os 10 maiores vértices
    vll uniao;
    for(ll i = 0; i < vtx[u].size(); i++) uniao.pb(vtx[u][i]);
    for(ll i = 0; i < vtx[v].size(); i++) uniao.pb(vtx[v][i]);
    sort(uniao.begin(), uniao.end());
    ll inicio = uniao.size() - 11;
    vll uniao_k;
    for(ll i = max(0LL, inicio); i < uniao.size(); i++) uniao_k.pb(uniao[i]);
    vtx[v] = uniao_k;
}

void solve(){
    ll n, q; cin >> n >> q;

    for(ll i = 1; i <= n; i++) make_set(i);

    while(q--){
        ll op; cin >> op;

        if(op == 1){
            ll u, v; cin >> u >> v;
            union_sets(u, v);
        }

        if(op == 2){
            ll v, k; cin >> v >> k;
            v = find_set(v);
            cout << (vtx[v].size() < k ? -1 : vtx[v][vtx[v].size()-k]) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
