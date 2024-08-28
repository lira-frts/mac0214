#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        string n; cin >> n;
        if(n.size() < 3 || n[0] != '1' || n[1] != '0' || n[2] == '0' || (n[2] == '1' && n.size() == 3)) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}
