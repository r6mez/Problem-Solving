/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// F. Empty array
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/372026/problem/F
// Time: 2/22/2025, 6:31:09 PM
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
    vi a(n); cin >> a;

    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    while (true) {
        bool printed = false;

        for (auto &[number, f] : freq){
            if (f > 0) {
                cout << number << " ";
                f--;
                printed = true;
            }
        }

        cout << "\n";

        if (printed == false) break;
    }
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

