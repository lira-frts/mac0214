#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        vector<ll> v;
        ll n, k; cin >> n >> k;
        for(ll i = 0; i < n; i++){ll a; cin >> a; v.push_back(a);}
        sort(v.begin(), v.end());
        ll pos = n - 2;
        while(k && pos >= 0){
            ll x = min(k, v[pos+1] - v[pos]);
            k -= x;
            v[pos] += x;
            pos-=2;
        }
        ll soma = 0, par = 1;
        for(ll i = n - 1; i >= 0; i--)
            if(par){soma += v[i]; par--;}
            else{soma -= v[i]; par++;}
        cout << soma << '\n';
        v.clear();
    }

    return 0;
}
