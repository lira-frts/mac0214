#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    vector<ll> resp(n);
    for(ll i = n - 1; i >= 0; i--)
        for(ll j = 1; j <= 4; j++){
            char c; cin >> c;
            if(c == '#') resp[i] = j;
        }
    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
