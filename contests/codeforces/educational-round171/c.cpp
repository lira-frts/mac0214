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
    set<ll> z, u;
    ll soma = 0;
    for(ll i = 1; i <= n; i++){
        char c; cin >> c;
        if(c == '0'){
            z.insert(i);
            soma += i;
        }
        else u.insert(i);
    }
    while(!u.empty()){
        bool flag = 1;
        ll y = *u.rbegin(); u.erase(y);
        while(!z.empty()){
            ll x = *z.rbegin(); z.erase(x);
            if(x < y){
                flag = 0; 
                break;
            }
        }
        if(flag && !u.empty()){
            ll x = *u.begin(); u.erase(x);
            soma += x;
            flag = 0;
        }
        if(flag) soma += y;
    }
    cout << soma << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
