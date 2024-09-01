#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
   
    ll x = 0; 
    while(x < s.size() && s[x] == '1') x++;
    x--;
    if(s.size() / x == x || (s.size() == 4)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--) solve();
}
