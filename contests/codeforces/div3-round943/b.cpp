/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    ll inicio = 0;
    for(ll i = 0; i < m; i++)
        if(a[inicio] == b[i]) inicio++;

    cout << inicio << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    
    while(t--) solve();
}
