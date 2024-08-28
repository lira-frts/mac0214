#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    vector<pair<ll, ll>> pontos;

    while(t--){
        ll n, s, m; cin >> n >> s >> m;
        bool flag = 0;

        for(ll i = 0; i < n; i++){
            ll l, r; cin >> l >> r;
            pontos.push_back({l, r});
        }
        pontos.push_back({0, 0}); pontos.push_back({m, m});        
        sort(pontos.begin(), pontos.end());
   
        for(int i = 0; i < n + 1; i++){
            ll l, r;
            r = pontos[i].second;
            l = pontos[i + 1].first;
   
            if(l - r >= s) flag = 1;
        }

        if(flag) cout << "yes\n";
        else cout << "no\n";

        pontos.clear();
    }

    return 0;
}
