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
    ll a = 0, b = 0, c = 0;
    for(ll i = 0; i < 9; i++){
        char x; cin >> x;
        if(x == 'A') a++;
        if(x == 'B') b++;
        if(x == 'C') c++;
    }
    if(a == 2) cout << "A\n";
    if(b == 2) cout << "B\n";
    if(c == 2) cout << "C\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
