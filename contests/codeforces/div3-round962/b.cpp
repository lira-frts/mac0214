#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, k; cin >> n >> k;
    char mat[n][n];

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> mat[i][j];

    for(ll i = 0; i < n; i += k){
        for(ll j = 0; j < n; j += k)
            cout << mat[i][j];
        cout << '\n';
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
