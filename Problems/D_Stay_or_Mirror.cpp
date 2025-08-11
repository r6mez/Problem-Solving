/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// D. Stay or Mirror
// URL: https://codeforces.com/contest/2130/problem/D
// Time: 7/31/2025, 8:03:50 PM
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
    vi p(n); cin >> p;

    int inv = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i] > p[j]) {
                inv++;
            }
        }
    }

    int answer = inv;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = 0;
        for (int j = 0; j < i; ++j) {
            if (p[j] > p[i]) l++;
        }

        for (int j = i + 1; j < n; ++j) {
            if (p[j] > p[i]) r++;
        }
        
        if (r < l) answer += r - l;
    }

    cout << answer << "\n";
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}