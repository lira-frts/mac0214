/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

void solve(){
    ll x; cin >> x;
    ll maximo = -1, resp;
    for(ll i = 1; i < x; i++){
        ll mdc = gcd(x, i);
        if(maximo < mdc + i){
            maximo = mdc + i;
            resp = i;
        }
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
