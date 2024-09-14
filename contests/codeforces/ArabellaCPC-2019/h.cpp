#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    if(n <= 2*k) cout << 10 << '\n';
    else cout << ((n+k-1)/(k)) * 5 << '\n';
}

signed main(){
    MAC0214 coxa
    solve();
    return 0;
}
