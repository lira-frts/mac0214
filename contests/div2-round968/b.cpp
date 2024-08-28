#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){ll a; cin >> a; v.push_back(a);}
        sort(v.begin(), v.end());
        cout << v[n / 2] << '\n';
        v.clear();
    }

    return 0;
}
