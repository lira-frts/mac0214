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
    string word; cin >> word;
    vll printedPair(word.size(),0);
    int nS = 0;
    for(int i = 0; i < word.size(); i++)
        if(word[i] == 'S'&& word[i+1] == 'S') nS++;
    for(char c : word)
        cout << (char)(c + 32);
    cout << '\n';
    while(nS){
        for(int i = 0; i < word.size(); i++){
            if(word[i] == 'S' && word[i+1] == 'S' && !printedPair[i]){
                cout << (char)('B');
                printedPair[i]++;
                nS--;
                i++;
                continue;
            }
            cout << (char)(word[i] + 32);
        }
        cout << '\n';
    }
    return; 
}

signed main(){
    MAC0214 muito coxa
    int t; //cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}
