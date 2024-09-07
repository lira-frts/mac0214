#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        if(n % 2 == 0) cout << -1 << '\n';
        else{
            for(ll i = n; i > n / 2 + 1; i--) cout << i << ' ';
            for(ll i = 1; i <= n / 2 + 1; i++) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}
