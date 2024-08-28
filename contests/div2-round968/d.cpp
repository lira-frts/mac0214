#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = ll(2e5 + 1);
set<ll> s;

void solve(){
    ll n, m; cin >> n >> m;
    ll maximo = -1;
    for(ll i = 0; i < n; i++){
        ll l, a; cin >> l; for(ll j = 0; j < l; j++){cin >> a; s.insert(a);}
        ll min1, min2;
        for(ll j = 0; j <= N; j++) if(s.find(j) == s.end()){min1 = j; break;}
        for(ll j = min1 + 1; j <= N; j++) if(s.find(j) == s.end()){min2 = j; break;}
        maximo = max(maximo, min2);
        s.clear();
    }
    if(maximo > m) cout << maximo * (m + 1) << '\n';
    else cout << maximo * (maximo + 1) + (maximo + 1 + m) * (m - maximo) / 2 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
