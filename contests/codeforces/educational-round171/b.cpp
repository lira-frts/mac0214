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
    if(n % 2 == 0){
        ll maximo = -1;
        for(ll i = 1; i < n; i += 2) maximo = max(maximo, v[i]-v[i-1]);
        cout << maximo << '\n';
    }
    else{
        ll minimo = 1e18+10;
        for(ll i = 0; i < n; i++){
            vll v2;
            for(ll j = 0; j < n; j++)
                if(j == i) continue;
                else v2.pb(v[j]);
            ll maximo = 1;
            for(ll j = 1; j < n; j += 2) maximo = max(maximo, v2[j]-v2[j-1]);
            minimo = min(minimo, maximo);
        }
        cout << minimo << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
