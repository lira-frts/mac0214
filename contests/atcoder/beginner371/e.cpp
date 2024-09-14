#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exp(ll k){
    if(k == 0) return 1;
    ll val = exp(k / 2) * exp(k / 2);
    if(k %= 2) val *= 2;
    return val;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    vector<ll> v(n), ultimo(n+1);

    for(ll i = 0; i < n; i++) cin >> v[i];

    for(ll i = 1; i <= n; i++) ultimo[i] = 0;

    ll soma = exp(n);
    for(ll i = 0; i < n; i++){
        ll dif = i - ultimo[v[i]];
        ultimo[v[i]] = i;
        soma -= exp(dif) - 1;
    }

    cout << soma << '\n';
}
