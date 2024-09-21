/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n), resp(n, 0);
    for(ll i = 0; i < n; i++) cin >> v[i];
    stack<ll> s;
    for(ll i = n-2; i >= 0; i--){
        while(1){
            if(s.empty()) break;
            ll topo = s.top();
            if(topo < v[i+1]) s.pop();
            else break;
        }
        s.push(v[i+1]);
        resp[i] = s.size();
    }
    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
