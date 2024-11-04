/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){
    ll n; cin >> n;
    vpll v(n);
    for(auto &[q, r]: v) cin >> q >> r;
    ll q; cin >> q;
    while(q--){
        ll t, d; cin >> t >> d; t--;
        if(d % v[t].F > v[t].S) cout << d + v[t].F - d % v[t].F + v[t].S << '\n';
        else cout << d + v[t].S - d % v[t].F << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
