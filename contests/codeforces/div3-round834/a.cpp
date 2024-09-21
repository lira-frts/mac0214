/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s; cin >> s;
    bool flag = 1;
    string t = "Yes";
    ll atual = 0;
    
    if(s[0] == t[0]) atual = 0;
    else if(s[0] == t[1]) atual = 1;
    else if(s[0] == t[2]) atual = 2; 
    else flag = 0;

    if(!flag){
        cout << "No\n";
        return;
    }
    
    for(ll i = 0; i < s.size(); i++){
        if(s[i] != t[atual % 3]) flag = 0;
        atual++;
    }

    cout << (!flag ? "No\n" : "Yes\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
