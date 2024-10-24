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
    vll toy(n), box(n-1);
    for(auto &t: toy) cin >> t;
    for(auto &b: box) cin >> b;
    sort(all(toy)); sort(all(box));
    for(ll i = 0; i < n-1; i++)
        if(toy[i] > box[i]){
            cout << -1 << '\n';
            return;
        }
    ll novo = toy[n-1];
    for(ll i = n-2; i >= 0; i--)
        if(toy[i+1] > box[i]) break;
        else novo = toy[i]; 
    cout << novo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
