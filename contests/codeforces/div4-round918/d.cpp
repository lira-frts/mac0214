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

string c = "bcd";

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    for(ll i = 0; i < n-2; i++){
        cout << s[i];
        if(c.find(s[i]) == -1 && c.find(s[i+1]) != -1){
            if(c.find(s[i+2]) != -1){
                cout << s[i+1] << '.';
                i++;
            }
            else cout << '.';
        }
    }
    cout << s[n-2] << s[n-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
