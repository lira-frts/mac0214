/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll r; cin >> r;
    ll cont = 0;
    for(ll x = -r; x <= r; x++){
        for(ll y = sqrt(r*r - x*x); y < sqrt((r+1)*(r+1) - x*x); y++){
            if(y * y + x * x < r * r || y * y + x * x >= (r+1) * (r+1)) continue;
            if(y == 0) cont++;
            else cont+=2;
        }
    }
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
