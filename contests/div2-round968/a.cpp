#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; string s; cin >> n >> s;
        if(s[0] == s[n - 1]) cout << "NO\n"; 
        else cout << "YES\n";
    }

    return 0;
}
