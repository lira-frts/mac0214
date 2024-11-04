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
    ll l = k-1, r = n-k;
    if(n == 1){
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }
    if(l == 0 || r == 0 || (l % 2 != r % 2)){
        cout << -1 << '\n';
        return;
    }
    if(l % 2 == 1){
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k+1 << '\n';
    }
    else{
        cout << 5 << '\n';
        cout << 1 << ' ' << k-1 << ' ' << k << ' ' << k+1 << ' ' << k+2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
