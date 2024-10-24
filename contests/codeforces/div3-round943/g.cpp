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

string s;

vll z_function(){
    ll n = s.size();
    vll z(n);
    ll l = 0, r = 0;
    for(ll i = 1; i < n; i++){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

void solve(){
    ll n, l, r; cin >> n >> l >> r;
    cin >> s;
    vll z = z_function();
    vll resp(n+1);
    for(ll k = 1; k <= sqrt(n); k++){
        ll inicio = 1, fim = n/k;
        while(inicio <= fim){
            ll meio = (inicio + fim) / 2;
            ll cont = 1;
            for(ll i = meio; i < n; i++)
                if(z[i] >= meio) cont++, i += meio-1;
            if(cont >= k) inicio = meio + 1;
            else fim = meio - 1;
        }
        resp[k] = fim;
    }
    for(ll l = 1; l <= sqrt(n); l++){
        ll k = 1;
        for(ll i = l; i < n; i++)
            if(z[i] >= l) k++, i += l-1;
        resp[k] = max(resp[k], l);
    }
    for(ll i = n-1; i >= 1; i--) resp[i] = max(resp[i], resp[i+1]);
    for(ll i = l; i <= r; i++) cout << resp[i] << ' '; cout << '\n'; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
