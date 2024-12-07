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
    string s; cin >> s; ll n = s.size();
    vll qtd(4);
    ll soma = 0;
    for(ll i = 0; i < n; i++){
        ll d = s[i] - '0';
        soma += d;
        if(d < 4) qtd[d]++;
    }
    vll v;
    for(ll i = 0; i <= min(qtd[2], 9LL); i++)
        for(ll j = 0; j <= min(qtd[3], 9LL); j++) v.pb(2*i+6*j);
    for(ll i = 0; i < v.size(); i++)
        if((v[i] + soma) % 9 == 0){
            cout << "yes\n";
            return;
        }
    cout << "no\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
