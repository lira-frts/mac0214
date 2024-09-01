#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = ll(2e5 + 10);
set<ll> s;
vector<ll> adj[N], mex(N);
vector<bool> vis(N);

// isso tá mt feio socorro
vector<ll> qtd_min1(N), mins1;

void dfs(ll v){
    vis[v] = 1;
    for(ll u: adj[v]){
        if(!vis[u]) dfs(u);
        mex[v] = max(mex[v], mex[u]);
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    ll max_min2 = -1;
    for(ll i = 0; i < n; i++){
        ll l, a; cin >> l; for(ll j = 0; j < l; j++){cin >> a; s.insert(a);}

        ll min1, min2;
        for(ll j = 0; j <= N; j++) if(s.find(j) == s.end()){min1 = j; break;}
        for(ll j = min1 + 1; j <= N; j++) if(s.find(j) == s.end()){min2 = j; break;}

        max_min2 = max(max_min2, min2);
        adj[min1].push_back(min2);
        mex[min2] = min2;

        qtd_min1[min1]++;
        mins1.push_back(min1);

        s.clear();
    }

    for(ll u = 0; u <= min(max_min2, m); u++) if(!vis[u]) dfs(u);
   
    ll x = -1;
    for(ll min1:mins1){x = max(x, min1); if(qtd_min1[min1] > 1) x = max(x, mex[min1]);}
    for(ll i = 0; i <= max_min2; i++) if(mex[i] == 0) mex[i] = max(x, i); 
    
    ll soma = 0;
    for(ll i = 0; i <= min(max_min2, m); i++) soma += mex[i];
    if(m > max_min2) soma += (max_min2 + 1 + m) * (m - max_min2) / 2;
    cout << soma << '\n';

    cout << mex[0] << ' ' << mex[1] << ' ' << mex[2] << endl;

    mins1.clear();
    for(ll i = 0; i <= max_min2; i++){qtd_min1[i] = 0; adj[i].clear(); vis[i] = 0; mex[i] = 0;}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
