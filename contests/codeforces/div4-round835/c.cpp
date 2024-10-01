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
    vpll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());
    vll resp(n);
    for(ll i = 0; i < n-1; i++) resp[v[i].second] = v[i].first - v[n-1].first;
    resp[v[n-1].second] = v[n-1].first - v[n-2].first;
    for(ll i = 0; i < n; i++) cout << resp[i] << ' '; cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
