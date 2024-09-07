#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v(200000), a(200002);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> v[i]; a[i] = 0;
        }
        a[n] = 0; a[n + 1] = 0;
        a[v[0]] = 1;
        bool flag = 1;
        for(ll i = 1; i < n; i++){
            if(a[v[i] - 1] == 0 && a[v[i] + 1] == 0){flag = 0; break;}
            else a[v[i]] = 1;
        }
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
