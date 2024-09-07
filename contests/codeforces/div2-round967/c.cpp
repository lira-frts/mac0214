#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> pai(1000);

void rec(ll x, ll y){
    cout << "? " << x + 1 << ' ' << y + 1 << '\n';
    cout.flush();
    ll z; cin >> z; z--;
    if(x == z) pai[y] = z;
    else rec(z, y);
}

int main(){
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < 1000; i++) pai[i] = -1; 
        pai[0] = -2; 
        for(ll i = 0; i < n; i++)
            if(pai[i] == -1) rec(0, i);
        cout << "! "; cout.flush();
        for(ll i = 1; i < n; i++) cout << i + 1 << ' ' << pai[i] + 1 << ' '; cout.flush();
        cout << "\n"; cout.flush();
    }

    return 0;
}
