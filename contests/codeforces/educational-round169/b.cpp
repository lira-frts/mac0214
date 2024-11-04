#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll l, r, L, R; cin >> l >> r >> L >> R;
        if(L > r || l > R) cout << 1 << '\n';
        else{
            ll soma = 0;
            if(l != L) soma++;
            if(r != R) soma++;
            soma += (min(r, R) - max(l, L));
            cout << soma << '\n';
        }
    }

    return 0;
}
