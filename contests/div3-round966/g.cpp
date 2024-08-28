#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = ll(1e5);
const ll INF = 1000;

vector<tuple<ll, ll, ll>> e[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n, m; cin >> n >> m;
        ll t0, t1, t2; cin >> t0 >> t1 >> t2;
        for(ll i = 0; i < m; i++){
            ll u, v, l1, l2; cin >> u >> v >> l1 >> l2; u--; v--;
            e[u].push_back({v, l1, l2}); e[v].push_back({u, l1, l2});
        }
        vector<int> dist(n+1, INF);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, n - 1});
        dist[n - 1] = 0;
        while(!pq.empty()){
	        auto[cur_dist, u] = pq.top(); pq.pop();
	        if(cur_dist > dist[u]) continue;
	        for(auto[v, l1, l2]: e[u]){
		        if(dist[v] > dist[u] + l1 && (t1 >= t0 - (dist[u] + l) || t2 <= t0 - (dist[u] + l1))){
			        dist[v] = dist[u] + l1;
			        pq.push({dist[v], v});
                }
                else if(dist[v] > dist[u] + max(t2 - t1, l2)){
                    dist[v] = dist[u] + max(t2 - t1, l2);
                    pq.push({dist[v], v});
                }
		    }
	    }
        for(ll i = 0; i < n; i++) cout << dist[i] << ' '; cout << endl;
        for(ll i = 0; i < n; i++) e[i].clear();
    }

    return 0;
}
