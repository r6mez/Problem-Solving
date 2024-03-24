#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll tents = a;
        tents += b/3;
        b %= 3;
        if(b > 0){
            if(c >= (3 - b)){
                tents++;
                c -= (3 - b);
            } else {
                cout << -1 << "\n";
                continue;
            }
        }
        tents += (c + 2) / 3;
        cout << tents << "\n";
    }
    return 0;
}