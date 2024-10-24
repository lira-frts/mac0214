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
    string s; cin >> s;

    if(s[0] == '1' || s[n-1] == '1'){
        cout << "yes\n";
        return;
    }

    for(ll i = 1; i < n-1; i++)
        if(s[i] == '1' && (s[i-1] == '1' || s[i+1] == '1')){
            cout << "yes\n";
            return;
        }

    cout << "no\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
