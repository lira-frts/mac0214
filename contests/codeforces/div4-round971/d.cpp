#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
#define vetor vector<ll>
#define pb push_back
#define bc back
 
#define all(x) x.begin(),x.end()
 
#define NO {cout << "NO" << "\n";}
#define YES {cout << "YES" << "\n";}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    long double pulo, pulox, puloy;
    ll x, y, k, mx;
 
    cin >> t;
 
    while(t!=0){
        cin >> x >> y >> k;
        
        mx=max(x, y);
 
        pulo=(ll)ceil((double)mx/(double)k);
        pulo=pulo*2;
        pulox=(ll)ceil((double)x/(double)k);
        puloy=(ll)ceil((double)y/(double)k);
        
        if(puloy>=pulox){
            cout << 2*puloy << "\n";
        }
        else{
            cout << (2*pulox)-1 << "\n";
        }
        
        t--;
    }
 
    return 0;
}
