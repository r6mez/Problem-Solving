/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Sum and Product
// URL: https://codeforces.com/problemset/problem/1857/F
// Time: 4/27/2025, 5:53:45 PM
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
const int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        int D = x*x - 4*y;
        if (D < 0) {
            cout << 0 << " ";
            continue;
        }
        int sq = sqrt(D);
        if (sq * sq != D) {
            cout << 0 << " ";
            continue;
        }
        int i1 = (x + sq);
        int i2 = (x - sq);
        if (i1 % 2 != 0 || i2 % 2 != 0) {
            cout << 0 << " ";
            continue;
        }
        i1 /= 2;
        i2 /= 2;
        if (i1 == i2) {
            cout << freq[i1] * (freq[i1]-1) / 2 << " ";
        } else {
            cout << freq[i1] * freq[i2] << " ";
        }
    }
    cout << "\n";
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