/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll l, r, x; cin >> l >> r >> x;
    ll a, b; cin >> a >> b;

    if(a == b){
        cout << 0 << '\n';
        return;
    }

    if(abs(a - b) >= x){
        cout << 1 << '\n';
        return;
    }

    ll la = a, ra = a;
    if(abs(l - a) >= x) la = l;
    if(abs(r - a) >= x) ra = r;

    if(abs(la - b) >= x || abs(ra - b) >= x){
        cout << 2 << '\n';
        return;
    }

    if(abs(la - r) >= x) la = r;
    if(abs(ra - l) >= x) ra = l;

    if(abs(la - b) >= x || abs(ra - b) >= x){
        cout << 3 << '\n';
        return;
    }

    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
