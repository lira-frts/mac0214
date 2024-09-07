#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll a, b; cin >> a >> b;
    if((b % 2 == 1 && (a < 2 || a % 2 == 1)) || (a % 2 == 1)) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
