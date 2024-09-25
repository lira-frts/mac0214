/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vll = vector<ll>;
using pl = pair<ll, ll>;
using lll = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vlll = vector<lll>;

void solve(){
    ll n; cin >> n;
    vector<string> v(n);
    set<string> st;
    for(ll i = 0; i < n; i++){
        cin >> v[i]; st.insert(v[i]);
    }
    string t;
    for(ll i = 0; i < n; i++){
        bool flag = 0;
        for(ll j = 0; j <= v[i].size(); j++){
            string inicio = v[i], fim = v[i];
            inicio.erase(inicio.begin() + j, inicio.end());
            fim.erase(fim.begin(), fim.begin() + j);
            if(st.find(inicio) != st.end() && st.find(fim) != st.end()) flag = 1;
            if(flag) break;
        }
        if(flag) t.push_back('1');
        else t.push_back('0');
    }
    cout << t << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
