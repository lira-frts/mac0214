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
    ll maximo = -1, ind;
    for(ll i = 1; i <= n; i++){
        ll a, b; cin >> a >> b;
        if(a <= 10 && b > maximo) maximo = b, ind = i;
    }
    cout << ind << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
