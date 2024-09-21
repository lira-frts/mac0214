/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s; cin >> s;
    for(ll i = 1; i < s.size(); i++)
        if(s[0] != s[i]){
            swap(s[0], s[i]);
            cout << "YES\n";
            cout << s << '\n';
            return;
        }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
