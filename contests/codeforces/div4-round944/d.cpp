/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s; cin >> s; ll n = s.size();
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) v[i] = (s[i] == '1');
   
    ll cont = 0;
    for(ll i = 0; i < n-1; i++)
        if(v[i] != v[i+1]) cont++;

    if(cont == 0){
        cout << 1 << '\n';
        return;
    }
    
    bool flag = 0;
    for(ll i = 0; i < n-1; i++)
        if(v[i] == 0 && v[i+1] == 1) flag = 1;

    if(v[0] == 1 && !flag) cont++;

    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
