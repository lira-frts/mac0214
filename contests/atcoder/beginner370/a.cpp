#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll l, r; cin >> l >> r;
    if(l == 1 && r == 0) cout << "Yes\n";
    else if(l == 0 && r == 1) cout << "No\n";
    else cout << "Invalid\n";
}
