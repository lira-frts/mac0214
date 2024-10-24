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
    ll n, k; cin >> n >> k;
    vpll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i].F;
    for(ll i = 0; i < n; i++) cin >> v[i].S;
    sort(v.begin(), v.end());
    ll soma = 0;
    multiset<ll> mst;
    ll resp = 1e18;
    for(ll i = 0; i < k-1; i++){
        soma += v[i].S;
        mst.insert(v[i].S);
    }
    for(ll i = k-1; i < n; i++){
        mst.insert(v[i].S);
        soma += v[i].S;
        resp = min(resp, v[i].F * soma);
        ll maximo = *mst.rbegin(); mst.erase(mst.find(maximo));
        soma -= maximo;
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
