#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
map<ll, ll> m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k; cin >> n >> k;

    ll dp = 0, dp_acc = 1, acc = 0; m[0] = 1;

    for(ll i = 0; i < n; i++){
        ll a; cin >> a;
        acc += a;
        dp = (dp_acc - m[acc - k] + MOD) % MOD;
        dp_acc = (dp_acc + dp) % MOD;
        m[acc] = (m[acc] + dp) % MOD;
    }

    cout << dp << '\n';
}
