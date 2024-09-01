#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string a, b; cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << ' ' << b << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
