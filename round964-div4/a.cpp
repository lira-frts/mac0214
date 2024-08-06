#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    while(n--){
        ll a; cin >> a;
        ll soma = 0;
        while(a){
            soma += a % 10;
            a /= 10;
        }
        cout << soma << '\n';
    }

    return 0;
}
