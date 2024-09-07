#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = ll(2e5);

vector<bool> vis(N);
vector<ll> resp(N), v(N), cor(N);

ll cont;

void dfs(ll x){
    ll y = v[x] - 1;
    if(vis[y] == 0){
        vis[y] = 1;
        cont += (1 - cor[y]);
        dfs(y);
        resp[y] = cont;
    }
}

void solve(){
    ll n; cin >> n;
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 0; i < n; i++){char c; cin >> c; cor[i] = (c == '1');}
    for(ll i = 0; i < n; i++)
        if(vis[i] == 0){
            cont = 0;
            vis[i] = 1;
            cont += (1 - cor[i]);
            dfs(i);
            resp[i] = cont;
        }
    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
    for(ll i = 0; i < n; i++) vis[i] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
