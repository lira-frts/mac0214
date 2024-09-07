#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v;
vector<bool> vv(ll(1e5) + 1);

void funcao(){
    for(ll i = 1; i <= ll(1e5) + 1; i++){
        ll m = i;
        bool flag = 1;
        while(m){
            ll x = m % 10;
            if(x != 0 && x != 1){flag=0; break;}
            m /= 10;
        }
        if(flag) v.push_back(i);
    }
    vv[0] = 1; vv[1] = 1;
    for(ll i = 1; i <= 100000; i++)
        for(ll j = 0; j < v.size(); j++)
            if(i < v[j]) continue;
            else if(i % v[j] == 0 && (vv[i / v[j]] == 1)) vv[i] = 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    funcao();

    while(t--){
        ll x; cin >> x;
        cout << (vv[x] ? "YES\n" : "NO\n");        
    }

    return 0;
}

