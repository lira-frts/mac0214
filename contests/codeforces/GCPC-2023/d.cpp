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
    int t, c, o, d, i; cin >> t >> c >> o >> d >> i;
    int min = t + c  + o + d + i;
    int max = 4*t + 6*c + 8*o + 12*d + 20*i;
    vll ans;
    while(min <= max){
        if(min+1 != max-1)
            ans.push_back(min++);
        ans.push_back(max--);
    }
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main(){
    MAC0214 muito coxa
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
