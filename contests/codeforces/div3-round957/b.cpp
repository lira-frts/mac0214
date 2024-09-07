#include <bits/stdc++.h>

#define MAC214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

void solve(){
    int length, k; cin >> length >> k;
    int ans = 0;
    vector<int> pieces(k);
    for(int i = 0; i < k; i++){
        cin >> pieces[i];
    }
    sort(pieces.begin(), pieces.end());
    for(int i : pieces){
        ans += i;
    } 
    cout << 2 * (ans - pieces[k-1]) - k + 1 << '\n';
}

signed main(){
    MAC214 coxa 
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
