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

}

signed main(){
    MAC0214 muito coxa
    int t, flag, copia, soma, ultimo, maissig; cin >> t;
    if(t<10){
        cout << t+1 << endl;
    }
    else{
        copia=t;
        flag=0;
        soma=0;
        while(t!=0){
            ultimo=t%10;
            soma+=10;
            t=t/10;
            if(t<10){
                if(t>ultimo){
                    soma+=t-1;
                }
                else{
                    if(t==ultimo){
                        flag=1;
                    }
                    soma+=t;
                }
                maissig=t;
                t=t/10;
            }
        }
        if(flag==1){
            while(copia!=0){
                ultimo=copia%10;
                copia=copia/10;
                if(maissig>ultimo){
                    soma-=1;
                    break;
                }
            }
        }
        cout << soma << endl;
    }
       
    return 0;
}

