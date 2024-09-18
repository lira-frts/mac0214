/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, s; cin >> n >> s;
    ll maximo = 0;
    set<ll> st;

    for(ll i = 0; i < n; i++){
        ll a; cin >> a; st.insert(a);
        maximo = max(maximo, a);
    }

    ll soma = 0, atual = 1;

    while(soma < s){
        if(st.find(atual) == st.end()){
            st.insert(atual);
            soma += atual;
        }
        maximo = max(maximo, atual);
        atual++;
    }

    cout << (soma == s && st.size() == maximo ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
