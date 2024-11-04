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
    vll v(n);
    for(ll &vi: v) cin >> vi;
    vll resp(n);
    for(ll i = 0; i < n; i++){
        ll cont = 0;
        for(ll j = i+1; j < n; j++)
            if(v[j] > v[i]) cont++;
        resp[i] = i+cont;
    }
    ll minimo = 1e18;
    for(ll i = 0; i < n; i++) minimo = min(minimo, resp[i]);
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
