#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;
bool capslock = false;

void toggleCaps(){
    if(capslock) capslock = false;
    else capslock = true;
}

void solve(){
    int n; cin >> n;
    string s, key; getline(cin >> ws, s);
    string ans = "";
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        cin >> key;
        if(key == "CapsLock") toggleCaps();
        else if(key == "Space") ans.append(" ");
        else if(key == "Backspace"){
            if(ans.size() > 0) ans.pop_back();
        }
        else{
            if(capslock) key[0]-=32;
            ans.append(key);
        }
    }    
    if(ans == s) cout << "Correct\n";
    else cout << "Incorrect\n";
}

signed main(){
    MAC0214 coxa
    solve();
    return 0;
}

