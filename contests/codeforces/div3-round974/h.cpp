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

const ll NMAX = 1e6;
const ll K = 500;

vll cont(NMAX+1);

void solve(){
    ll n, q; cin >> n >> q;
    vll v(n);
    for(ll &x: v) cin >> x, cont[x] = 0;

    vvll qs(q, vll(3));
    for(ll i = 0; i < q; i++) cin >> qs[i][0] >> qs[i][1], qs[i][2] = i;

    auto cmp = [](vll &a, vll &b){
        if(a[0]/K != b[0]/K) return a[0]/K < b[0]/K;
        return a[1] < b[1];
    };

    sort(qs.begin(), qs.end(), cmp);

    vll resp(q);
 
    ll l = 0, r = 0, impar = 1;
    cont[v[0]]++;
 
    for(auto &c: qs){
        c[0]--, c[1]--;
 
        while(r < c[1]){
            cont[v[++r]]++;
            if(cont[v[r]] % 2) impar++;
            else impar--;
        }
 
        while (r > c[1]){
            cont[v[r]]--;
            if(cont[v[r--]] % 2) impar++;
            else impar--;
        }
        
        while(l < c[0]){
            cont[v[l]]--;
            if(cont[v[l++]] % 2) impar++;
            else impar--;
        }
        
        while(l > c[0]){
            cont[v[--l]]++;
            if(cont[v[l]] % 2) impar++;
            else impar--;
        }
 
        resp[c[2]] = impar;
    }
 
    for(ll c: resp) cout << (c ? "NO\n" : "YES\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
