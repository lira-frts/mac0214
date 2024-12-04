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
#define rall(a) a.rbegin(), a.rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll minimo = 1e18;
    for(ll i = 0; i < n-1; i++){
        vll num;
        ll qtd1 = 0;
        for(ll j = 0; j < n; j++){
            ll x;
            if(j == i) x = 10*(s[j]-'0')+(s[j+1]-'0'), j++;
            else x = s[j]-'0';
            if(x == 0){
                cout << "0\n";
                return;
            }
            if(x == 1) qtd1++;
            num.pb(x);
        }
        if(qtd1 == num.size()){
            minimo = min(minimo, 1LL); 
            continue;
        }
        ll soma = -qtd1;
        for(ll x: num) soma += x;
        minimo = min(minimo, soma);
    }
    cout << minimo << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
