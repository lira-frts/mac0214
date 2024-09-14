#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q; cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<ll> pop(n), acc(n+1);
    
    for(ll i = 0; i < n; i++){cin >> v[i].first; v[i].second = i+1;}

    for(ll i = 0; i < n; i++) cin >> pop[i];
    
    acc[0] = 0;
    for(ll i = 1; i <= n; i++) acc[i] = acc[i - 1] + pop[i - 1]; 

    cin >> q;

    while(q--){
        ll l, r; cin >> l >> r;
        pair<ll, ll> minimo = {l, 0}, maximo = {r+1, 0};
        auto lower1 = lower_bound(v.begin(), v.end(), minimo);
        ll x1 = (*lower1).second;
        auto lower2 = lower_bound(v.begin(), v.end(), maximo); lower2--;
        ll x2 = (*lower2).second;
         
        if(x2 >= x1) cout << acc[x2] - acc[x1 - 1] << '\n'; 
        else cout << 0 << '\n';
    }
}
