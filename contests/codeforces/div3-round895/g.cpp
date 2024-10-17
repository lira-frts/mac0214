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
    vll v(n);
    for(auto &vi: v) cin >> vi;
    ll prod = 1;
    bool flag = 0;
    for(ll i = 0; i < n; i++){
        prod *= v[i];
        if(prod > 2*n) flag = 1;
    }
    if(flag){
        ll l = 0, r = n-1;
        while(v[l] == 1) l++; cout << l+1 << ' ';
        while(v[r] == 1) r--; cout << r+1 << '\n';
    }
    else{
        vll soma(n+1, 0), produto(n+1, 1);
        ll lresp = 1, rresp = 1, maximo = -1;
        for(ll i = 1; i <= n; i++) soma[i] = soma[i-1] + v[i-1];
        for(ll i = 1; i <= n; i++) produto[i] = produto[i-1] * v[i-1];

        vll indices;
        for(ll i = 0; i < n; i++)
            if(v[i] > 1) indices.pb(i+1);
        for(ll i = 0; i < indices.size(); i++)
            for(ll j = i; j < indices.size(); j++){
                ll l = indices[i], r = indices[j];
                ll t = soma[l-1] + produto[r] / produto[l-1] + soma[n] - soma[r];
                if(t > maximo) maximo = t, lresp = l, rresp = r;
            }
        cout << lresp << ' ' << rresp << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
