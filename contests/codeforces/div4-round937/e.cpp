/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    for(ll div = 1; div <= n; div++){
        if(n % div != 0) continue;
    
        ll pos = -1;
        bool flag = 1;

        for(ll i = 0; i < n; i++)
            if(s[i] != s[i % div])
                if(pos == -1) pos = i;
                else if(i % div != pos % div) flag = 0;

        if(!flag) continue;
        
        if(pos == -1){
            cout << div << '\n';
            return;
        }

        ll cont1 = 0, cont2 = 0;
        for(ll i = pos % div; i < n; i += div){
            if(s[i] == s[pos % div]) cont1++;
            if(s[i] == s[pos]) cont2++;
        }
        
        if(cont1 == n/div - 1 || cont2 == n/div - 1){
            cout << div << '\n';
            return;
        }
    }        
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
