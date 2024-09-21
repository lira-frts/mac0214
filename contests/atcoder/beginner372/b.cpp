/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll m; cin >> m;
    vector<ll> v;
    while(m){
        ll exp = -1, val = 1;
        while(val <= m) exp++, val *= 3;
        v.push_back(exp); m -= val/3; 
    }
    cout << v.size() << '\n';
    for(ll i = 0; i < v.size(); i++) cout << v[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
