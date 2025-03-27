/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Olympiad Date
// URL: https://codeforces.com/contest/2091/problem/0
// Time: 3/25/2025, 4:42:37 PM
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
    multiset<int> should = {0, 0, 1, 3, 2, 0, 2, 5};
    
    int n; cin >> n;
    vi a(n); cin >> a;

    for (int i = 0; i < n; i++){
        int x = a[i];
        if(should.count(x)) should.erase(should.find(x));
        if(should.empty()) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << "0\n";
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