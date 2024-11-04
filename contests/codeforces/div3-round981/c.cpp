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
    for(ll i = 1; i < n/2; i++){
        if(v[i] == v[n-1-i]) continue;
        if(v[i] == v[i-1] || v[n-1-i] == v[n-i]) swap(v[i], v[n-1-i]);
    }
    ll soma = 0;
    for(ll i = 0; i < n-1; i++)
        if(v[i] == v[i+1]) soma++;
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
