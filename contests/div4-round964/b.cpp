#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    while(n--){
        ll a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll soma = 0;

        ll x[4];

        // a1, b1 e a2, b2
        x[0] = a1, x[1] = b1, x[2] = a2, x[3] = b2;
        if((x[0] >= x[1] && x[2] > x[3]) || (x[0] > x[1] && x[2] >= x[3])) soma += 2;

        // a1, b2 e a2, b1
        x[0] = a1, x[1] = b2, x[2] = a2, x[3] = b1;
        if((x[0] >= x[1] && x[2] > x[3]) || (x[0] > x[1] && x[2] >= x[3])) soma += 2;
        
        cout << soma << '\n';
    }
    
    return 0;
}
