#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    if(n > k + 1) cout << "Kilani\n";
    else if(n % 2) cout << "Kilani\n";
    else cout << "Ayoub\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
