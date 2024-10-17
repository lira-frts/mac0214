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

ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    ll mdc = gcd(x, y), mmc = (x*y)/mdc;
    ll tx = n/x-n/mmc, ty = n/y-n/mmc, score = 0;
    score += (n+(n-tx+1))*(tx)/2;
    score -= (1+ty)*ty/2;
    cout << score << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
