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
    set<ll> st; st.insert(0);
    ll soma = 0, resp = 0;
    while(n--){
        ll x; cin >> x;
        soma += x;
        if(st.find(soma) != st.end()){
            soma = 0, resp += 1;
            st.clear();
            st.insert(0);
        }
        else st.insert(soma);
    }
    cout << resp << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
