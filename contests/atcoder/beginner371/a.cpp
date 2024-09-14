#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char sab, sac, sbc; cin >> sab >> sac >> sbc;

    if(sab == '>' && sac == '>')
        if(sbc == '>') cout << "B\n";
        else cout << "C\n";

    else if(sab == '<' && sbc == '>')
        if(sac == '>') cout << "A\n";
        else cout << "C\n";

    else
        if(sab == '>') cout << "A\n";
        else cout << "B\n";
}
