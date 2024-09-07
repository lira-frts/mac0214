#include <bits/stdc++.h>

#define MAC214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> arr = {a,b,c};
    for(int i = 0; i < 5; i++){
        sort(arr.begin(), arr.end());
        arr[0] += 1;
    }
    cout << arr[0] * arr[1] * arr[2] << '\n';
    return;
}

signed main(){
    MAC214 coxa
    int t; cin >> t; 
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
