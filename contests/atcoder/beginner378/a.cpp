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
    vll v(4);
    for(ll &vi: v) cin >> vi;
    sort(all(v));
    ll cont = 0;
    if(v[0] == v[1]){
        cont++;
        if(v[2] == v[3]) cont++;
    }
    else if(v[1] == v[2]) cont++;
    else if(v[2] == v[3]) cont++;
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
