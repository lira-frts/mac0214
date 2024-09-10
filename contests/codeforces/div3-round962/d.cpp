#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, x; cin >> n >> x;

    ll cont = 0;

    for(ll a = 1; a <= n; a++)
        for(ll b = 1; b <= n / a; b++)
            if(n < a * b || x < a + b) continue;
            else cont += min((n - a * b) / (a + b), x - (a + b));
    
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
