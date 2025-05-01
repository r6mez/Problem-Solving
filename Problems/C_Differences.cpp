#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 132120577;

void Ramez() {
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x, f; cin >> x >> f;
        freq[x] = f;
    }
    
    map<int, int> diffs;
    for(auto [x1, f1] : freq){
        for(auto [x2, f2] : freq){
            if(x1 <= x2) continue;
            // cout << abs(x1 - x2) << " " << f1 * f2 << "\n";
            diffs[abs(x1 - x2)] += (f1 * f2)%MOD;
        }
    }

    vi a(MOD + 5);
    for(auto [diff, pairs] : diffs){
        a[diff] = pairs;
    }

    for (int i = 1; i < a.size(); i++){
        a[i] = (a[i]%MOD + a[i - 1]%MOD)%MOD;
    }
    
    // for (int i = 0; i < 10; i++){
    //     cout << a[i] << " ";
    // } cout << "\n";
    
    
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int sum = a[r] - a[l - 1];
        cout << sum << "\n";
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}