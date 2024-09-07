#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;

    while(t--){
        ll a, b; char c; cin >> a >> c >> b;
        if(a >= 12){
            if(a == 12) cout << "12:";
            else{
                a -= 12;
                if(a < 10) cout << 0;
                cout << a << ":";
            }
   
            if(b < 10) cout << 0;
            cout << b << " PM\n";
        }
        else{
            if(a == 0) cout << "12:";
            else{
                if(a < 10) cout << 0;
                cout << a << ":";
            }
            if(b < 10) cout << 0;
            cout << b << " AM\n";
        }
    }

    return 0;
} 
