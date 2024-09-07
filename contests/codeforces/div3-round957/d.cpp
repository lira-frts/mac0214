#include <bits/stdc++.h>

#define MAC214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    string river;
    cin >> river; 
    int pos = -1;
    bool tronco = true, morreu = false;
    while(pos < n){
        if(tronco == true){
            if(pos >= n - m) break;
           tronco = false;
            for(int i = m; i > 0; i--){
                if(river[pos + i] == 'L'){
                    pos += i;
                    tronco = true;
                    break;
                }
            }
            if(!tronco) pos += m;
        }
        if(river[pos] == 'W') {
            k--;
            pos++;
            if(river[pos] == 'L') tronco = true;
        }
        if(river[pos] == 'C' || k < 0){
            cout << "NO\n";
            morreu = true; // : (
            break;
        }
    }
    if(!morreu) cout << "YES\n";

    return;
}

signed main(){
    MAC214 coxa
    int t; cin >> t;
    for(int i = 0; i < t; i++) { 
        solve();
    }
    return 0;
}
