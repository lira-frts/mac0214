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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const ll INF = 1e18;

void dijkstra(vvpll &E, vvll &dist, vll &s){
    set<vll> st;
    st.insert({0, 0, 0}); dist[0][0] = 0;
    while(!st.empty()){
        vll vec = *st.begin(); st.erase(vec);
        ll d = vec[0], v = vec[1], b = vec[2];
        if(s[v] < s[b]) b = v;
        for(auto &[u, w]: E[v]){
            if(dist[u][b] > d + w * s[b]){
                st.erase({dist[u][b], u, b});
                dist[u][b] = d + w * s[b];
                st.insert({dist[u][b], u, b});
            }
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vvpll E(n);
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E[u].pb({v, w}); E[v].pb({u, w});
    }
    vll s(n);
    for(ll &si: s) cin >> si;
    vvll dist(n, vll(n, INF));
    dijkstra(E, dist, s);
    ll minimo = INF;
    for(ll i = 0; i < n; i++) minimo = min(minimo, dist[n-1][i]);
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
