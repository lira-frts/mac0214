#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;

    vector<bool> v(n);

    for(ll i = 0; i < m; i++){
        ll a; char s; cin >> a >> s; a--;
        if(s == 'F'){cout << "No\n"; continue;}
        if(v[a]) cout << "No\n";
        else{v[a] = 1; cout << "Yes\n";}
    }
}
