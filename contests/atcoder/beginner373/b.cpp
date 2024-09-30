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

void solve(){
    string s; cin >> s;
    ll cont = 0;
    ll ant = s.find('A');
    for(ll i = 'B'; i <= 'Z'; i++){
        ll atual = s.find(i);
        cont += abs(atual - ant);
        ant = atual;  
    }
    cout << cont << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
