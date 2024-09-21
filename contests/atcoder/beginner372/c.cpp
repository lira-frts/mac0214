/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    ll cont = 0;
    for(ll i = 0; i < n - 2; i++)
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') cont++;
    while(q--){
        ll x; cin >> x; x--;
        if(x < n - 2 && s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') cont--;
        if(x > 0 && x < n - 1 && s[x-1] == 'A' && s[x] == 'B' && s[x+1] == 'C') cont--;
        if(x > 1 && x < n && s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C') cont--;
        cin >> s[x];
        if(x < n - 2 && s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') cont++;
        if(x > 0 && x < n - 1 && s[x-1] == 'A' && s[x] == 'B' && s[x+1] == 'C') cont++;
        if(x > 1 && x < n && s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C') cont++;
        cout << cont << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
