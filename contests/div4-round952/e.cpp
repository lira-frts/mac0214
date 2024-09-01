#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll maximo = 0;
    for(ll i = 1; i <= x; i++)
        for(ll j = 1; j <= y; j++)
            if(k % (i * j) == 0 && k / (i * j) <= z){
                ll atual = (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1);
                maximo = max(maximo, atual);
            }
    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
