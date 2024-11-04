#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> v(n), s(2*n+1);
    for(ll i = 1; i <= n; i++) cin >> v[i-1], s[i] = s[i-1] + v[i-1];
    for(ll i = n+1; i <= 2*n; i++) s[i] = s[i-1] + v[i-(n+1)];
    while(q--){
        ll l, r; cin >> l >> r; l--, r--;
        ll i = l/n, j = r/n;
        l %= n, r %= n;
        cout << s[n] * (j-i+1) - (s[i+l] - s[i]) - (s[j+n] - s[j+r+1]) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
