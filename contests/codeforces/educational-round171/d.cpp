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

ll n;

ll f(ll r, vll &acc1, vll &acc2, vll &acc3, vll &acc4){
    ll x = upper_bound(all(acc3), r) - acc3.begin() - 1;
    ll resto = r-acc3[x];
    return acc4[x] + acc2[x] - (acc2[x+resto] + (acc1[x+resto] - acc1[x]) * (n-(x+resto)));
}

void solve(){
    // acc1[i] := soma acumulada de v[0] até v[i-1]
    // acc2[i] := soma dos intervalos do tipo (i, r), com r >= i
    // acc3[i] := quantos intervalos tem do tipo (l, r), com l <= i
    // acc4[i] := soma acumulada dos intervalos do tipo (l, r), com l <= i
    cin >> n;
    vll v(n), acc1(n+1);
    for(ll i = 0; i < n; i++) cin >> v[i], acc1[i+1] = acc1[i] + v[i];
    vll acc2(n+1); 
    for(ll i = n-1; i >= 0; i--) acc2[i] = acc2[i+1] + v[i] * (n-i);
    vll acc3(n+1), acc4(n+1);
    for(ll i = 1; i <= n; i++){
        acc3[i] = acc3[i-1] + (n-i+1);
        acc4[i] = acc4[i-1] + acc2[i-1];
    }
    ll q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        ll fr = f(r, acc1, acc2, acc3, acc4);
        ll fl = f(l-1, acc1, acc2, acc3, acc4);
        cout << fr - fl << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
