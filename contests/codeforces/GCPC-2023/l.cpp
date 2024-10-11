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
    string s; cin >> s;
    bool possible = false;
    int contAbre = 0, contFecha = 0;
    int printIndex;

    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == '(') contAbre++;
        else if(s[i] == ')') contFecha++;

        if(contAbre == contFecha){
            if((s.size()%(i+1)) == 0){
                for(int j = i+1; j < s.size() && !possible; j+=i+1){
                    int index = 0;
                    for(int k = j; k < j+i+1; k++){
                        if(s[k] != s[index++]){
                            possible = true;
                            printIndex = i+1;
                            break;
                        }
                    }
                    if(possible)break;
                }
                break;
            }
            else {
                possible = true;
                printIndex = i+1;
                break;
            }
        }
    }
    if(possible){
        for(int i = printIndex; i < s.size(); i++) cout << s[i];
        for(int i = 0; i < printIndex; i++) cout << s[i];
        cout << '\n';
    }
    else cout << "no\n";
}

signed main(){
    MAC0214 muito coxa
    int t=1;
    while(t--) solve();
    return 0;
}
