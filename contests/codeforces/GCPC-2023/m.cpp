#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

using vll = vector<int>;
using pll = pair<int, int>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

void solve(){
    int d; cin >> d;
    if(d >= 10) cout << "1 2 3\n";
    else if(d <= 2) cout << "4 29 100\n";
    else cout << "1 100 88\n";
}

signed main(){
    MAC0214 muito coxa
    int t=1;
    while(t--) solve();
    return 0;
}
