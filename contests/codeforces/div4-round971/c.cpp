#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    double x, y, k; cin >> x >> y >> k;
    if(ceil(x/k) > ceil(y/k)) cout << 2 * ceil(x/k) - 1 << '\n';
    else cout << 2 * ceil(y/k) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
