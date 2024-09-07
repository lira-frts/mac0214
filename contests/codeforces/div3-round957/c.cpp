#include <bits/stdc++.h>

#define MAC214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k; 
    vector<int> arr;
    for(int i = n; i > 0; i--){
        arr.push_back(i);
    }
    
    sort(arr.begin() + (n - m), arr.end());

    for(auto i : arr) cout << i << ' ';
    cout << '\n';
}

signed main(){
    MAC214 coxa
    int t; cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
    return 0;
}

