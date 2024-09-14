#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n; cin >> n;
    ll resto = n % 5;
    string s = "aeiou";
    for(ll i = 0; i < 5; i++){
        for(ll j = 0; j < n / 5; j++) cout << s[i];
        if(resto){cout << s[i]; resto--;}
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
}
