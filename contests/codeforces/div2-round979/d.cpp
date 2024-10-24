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
    ll n, q; cin >> n >> q;
    ll p = 0, u = 0;
    set<pll> st;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x; x--;
        u = max(u, x);
        if(i == u){
            st.insert({p, u});
            p = ++u;
        } 
    }
    if(p < n) st.insert({p, u});
    string s; cin >> s;

    ll cont = 0;

    for(ll i = 0; i < n-1; i++){
        if(s[i] == 'L' && s[i+1] == 'R'){
            auto lower = --st.lower_bound({i+1, i+1});
            auto [p, u] = *lower;
            if(i < u) cont++;
        }
    }

    while(q--){
        ll ind; cin >> ind; ind--;

        if(s[ind] == 'L' && s[ind+1] == 'R'){
            auto lower = --st.lower_bound({ind+1, ind+1});
            auto [p, u] = *lower;
            if(ind < u) cont--;
        }
        if(s[ind-1] == 'L' && s[ind] == 'R'){
            auto lower = --st.lower_bound({ind, ind});
            auto [p, u] = *lower;
            if(ind-1 < u) cont--;
        }

        if(s[ind] == 'L') s[ind] = 'R';
        else s[ind] = 'L';

        if(s[ind] == 'L' && s[ind+1] == 'R'){
            auto lower = --st.lower_bound({ind+1, ind+1});
            auto [p, u] = *lower;
            if(ind < u) cont++;
        }
        if(s[ind-1] == 'L' && s[ind] == 'R'){
            auto lower = --st.lower_bound({ind, ind});
            auto [p, u] = *lower;
            if(ind-1 < u) cont++;
        }
        cout << (cont == 0 ? "yes\n" : "no\n");
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
