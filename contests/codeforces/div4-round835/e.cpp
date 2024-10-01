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

#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){
    ll n; cin >> n;
    vll v(n), z(n, 0), u(n, 0);
    for(ll &x: v) cin >> x;
    
    for(ll i = 0; i < n; i++){
        if(i > 0) z[i] = z[i-1], u[i] = u[i-1];
        if(v[i]) u[i]++;
        else z[i]++;
    }

    ll inv = 0;
    for(ll i = 0; i < n; i++)
        if(v[i] == 0) inv += u[i];

    ll maximo = inv;

    

    for(ll i = 0; i < n; i++){
        ll novo = inv;
        if(v[i] == 0){
            if(i > 0) novo -= u[i-1];
            novo += (z[n-1] - z[i]);
        }
        if(v[i] == 1){
            novo -= (z[n-1] - z[i]);
            if(i > 0) novo += u[i-1];
        }
        maximo = max(maximo, novo);
    }

    cout << maximo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
