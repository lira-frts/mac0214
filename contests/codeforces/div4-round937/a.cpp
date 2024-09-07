#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;

        if(a < b && b < c) cout << "STAIR\n";
        else if(a < b && b > c) cout << "PEAK\n";
        else cout << "NONE\n";
    }

    return 0;
}
