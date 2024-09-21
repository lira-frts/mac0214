/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s; cin >> s;
    string t;
    for(ll i = 0; i < s.size(); i++)
        if(s[i] != '.') t.push_back(s[i]);
    cout << t << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
}
