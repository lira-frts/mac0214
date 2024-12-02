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
    int n; cin >> n;
    vll blue(n), red(n);
    for(int &i : blue) cin >> i;
    for(int &i : red) cin >> i;
    if(n == 1){
        cout << abs(blue[0]-red[0]);
        return;
    }
    sort(blue.begin(),blue.end());
    sort(red.rbegin(),red.rend());
    vll ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = blue[i]+red[i];
    }
    sort(ans.begin(),ans.end());
    cout << ans[ans.size()-1] - ans[0] << '\n';
}

signed main(){
    MAC0214 muito coxa
    int t = 1;
    while(t--) solve();
    return 0;
}
