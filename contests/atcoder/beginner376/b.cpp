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
    ll n, q; cin >> n >> q;
    ll soma = 0, l = 1, r = 2;
    while(q--){
        char h; cin >> h;
        ll t; cin >> t;
        if(h == 'R'){
            if(r >= t && (l > r || t > l) || r <= t && (l > t || l < r)) soma += abs(r-t), r = t;
            else soma += n-abs(r-t), r = t;
        }
        else{
            if(l >= t && (r > l || t > r) || l <= t && (r > t || r < l)) soma += abs(l-t), l = t;
            else soma += n-abs(l-t), l = t;
        }
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
