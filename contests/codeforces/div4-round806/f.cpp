/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pl = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vlll = vector<lll>;

void solve(){
    ll n; cin >> n; 
    vll v(n), aux;
    for(ll i = 0; i < n; i++) cin >> v[i];
    ll soma = 0;
    for(ll i = 0; i < n; i++){
        if(i+1 <= v[i]) continue;
        auto lower = lower_bound(aux.begin(), aux.end(), v[i]);
        soma += lower - aux.begin();
        aux.push_back(i+1);
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
