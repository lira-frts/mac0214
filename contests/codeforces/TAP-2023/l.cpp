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
    int a1, a2, b1, b2;

    cin >> a1 >> a2;
    cin >> b1 >> b2;

    if(a1+b1>a2+b2) cout << "A" << "\n";
    else if(a1+b1<a2+b2) cout << "P" << "\n";
    else cout << "D" << "\n";
}

signed main(){
    MAC0214 muito coxa
    int t; t=1;
    while(t--) solve();
    return 0;
}
