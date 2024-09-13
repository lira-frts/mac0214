#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    ll resp = 0;

    for(ll i = 2; i <= n; i++) resp += (i * (i - 1));

    cout << setprecision(16);
    cout << (double) resp / n << '\n';
}
