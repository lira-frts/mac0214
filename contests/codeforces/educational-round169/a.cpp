#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        vector<ll> v;
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){ll a; cin >> a; v.push_back(a);}
        if(n > 2 || (v[1] - v[0] == 1)) cout << "no\n";
        else cout << "yes\n";
        v.clear();
    }

    return 0;
}
