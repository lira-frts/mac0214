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

const ll INF = 1e15;

void floyd_warshall(vvll &E, vvll &custo, vvll &dist){
    ll n = E.size();
	for(ll i = 0; i < n; i++)
		for(ll j = 0; j < n; j++)
            if(i == j) dist[i][j] = 0;
            else if(E[i][j]) dist[i][j] = custo[i][j];
            else dist[i][j] = INF;
	for(ll k = 0; k < n; k++)
        for(ll i = 0; i < n; i++)
			for(ll j = 0; j < n; j++)
			    dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
}

void solve(){
    ll n, m, q; cin >> n >> m >> q;

    vvll E1(n, vll(n)), custo(n, vll(n));
    vpll E2(m);
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        E2[i] = {u, v};
        E1[u][v] = 1, E1[v][u] = 1, custo[u][v] = w, custo[v][u] = w;
    }
    
    vvll qs;
    for(ll i = 0; i < q; i++){
        ll op; cin >> op;
        if(op == 1){
            ll x; cin >> x; x--;
            auto [u, v] = E2[x];
            E1[u][v] = 0, E1[v][u] = 0;
            qs.pb({1, u, v});
        }
        if(op == 2){
            ll u, v; cin >> u >> v; u--, v--;
            qs.pb({2, u, v});
        }
    }
    
    vvll dist(n, vll(n));
    floyd_warshall(E1, custo, dist);
   
 
    vll resp;
    for(ll i = q-1; i >= 0; i--){
        ll op = qs[i][0], u = qs[i][1], v = qs[i][2];
        if(op == 1){
            dist[u][v] = dist[v][u] = min(dist[u][v], custo[u][v]);
            for(ll x = 0; x < n; x++)
                for(ll y = 0; y < n; y++){
                    ll c1 = dist[x][u] + custo[u][v] + dist[v][y];
                    ll c2 = dist[x][v] + custo[v][u] + dist[u][y];
                    dist[x][y] = dist[y][x] = min({dist[x][y], c1, c2});
                }
        }
        if(op == 2)
            if(dist[u][v] == INF) resp.pb(-1);
            else resp.pb(dist[u][v]);
    }

    for(ll i = resp.size()-1; i >= 0; i--) cout << resp[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
