#include <bits/stdc++.h>

#define MAC0214 std::ios_base::sync_with_stdio(false);
#define muito std::cout.tie(NULL);
#define coxa std::cin.tie(NULL);
#define int long long
using namespace std;
#define pb push_back
#define bc push_back
#define all(x) x.begin(),x.end()
using vll = vector<int>;
using pll = pair<double, char>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

void solve(){
    int n, s1, p1;
    double tempo, time, mb, mbp, mbs;
    vpll fila;

    cin >> n >> mb;
    p1=s1=0;
    for(int i=0; i<n; i++){
        double in; char l;
        cin >> l >> in;
        if(l=='P'){
            fila.pb({in, l});
            p1++;
        }
        else{ 
            fila.pb({in, l});
            s1++;
        }
    }
    mbp=(double)(mb*0.75)/p1;
    mbs=(double)(mb*0.25)/s1;
    if(s1==0) mbp=mb/p1;
    if(p1==0) mbs=mb/s1;
        
    sort(all(fila));

    tempo=0;
    for(int i=0; i<n; i++){
        if(fila[i].second=='P'){
            time=fila[i].first/mbp;
            tempo+=time;
            for(int j=i+1; j<n; j++){
                if(fila[j].second=='P'){
                    fila[j].first=fila[j].first-(mbp*time);
                }
                else{
                    fila[j].first=fila[j].first-(mbs*time);
                }
            }
            p1--;
            mbp=(double)(mb*0.75)/p1;
        }
        else{
            time=fila[i].first/mbs;
            tempo+=time;
            for(int j=i+1; j<n; j++){
                if(fila[j].second=='P'){
                    fila[j].first=fila[j].first-(mbp*time);
                }
                else{
                    fila[j].first=fila[j].first-(mbs*time);
                }
            }
            s1--;
            mbs=(double)(mb*0.25)/s1;
        }
        if(s1==0){
            mbp=(double)mb/p1;
        }
        else if(p1==0){
            mbs=(double)mb/s1;
        }
    }
    cout << setprecision(14);
    cout << tempo << "\n";
}

signed main(){
    MAC0214 muito coxa
    int t=1;
    while(t--) solve();
    return 0;
}
