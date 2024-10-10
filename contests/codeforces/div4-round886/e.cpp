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
    ll n, c; cin >> n >> c;
    ll soma = 0;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        soma += x;
        c -= x * x;
    }
    ll a = 1, b = soma/n; c = -c/(4*n);
    ll d = b*b - 4*a*c;
    cout << (-b+(ll)sqrt(d))/(2*a) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
