#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

bool isBitAvailable(int L, int R, int i) {
    int block = 1LL << (i + 1);
    int half  = 1LL << i;
    int pos   = L % block;
    int firstOne = (pos < half)
                       ? L + (half - pos)
                       : L;
    return firstOne <= R;
}


bool isSet(int n, int i){
    return (n >> i) & 1LL;
}

void solve() {
    int a, b, l, r; cin >> a >> b >> l >> r;


    if(b > a){
        cout << "NO\n";
        return;
    }


    for (int i = 0; i <= 31; i++){
        if(!isSet(a, i) && isSet(b, i)){
            cout << "NO\n";
            return;
        }

        if(isSet(a, i) && !isSet(b, i)){
            if(!isBitAvailable(l, r, i)){
                cout << "NO\n";
                return;
            }
        }
    }
    
    cout << "YES\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}