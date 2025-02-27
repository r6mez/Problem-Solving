/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Card Game
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/373244/problem/D
// Time: 2/27/2025, 4:28:09 PM
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
int MOD = 1000000007;



void zizo() {
    string m, r, a;
    cin >> m >> r >> a;
    queue<char> m1, r1, a1;
    
    for (int i = 0; i < m.size(); ++i) {
        m1.push(m[i]);
    }
    for (int i = 0; i < r.size(); ++i) {
        r1.push(r[i]);
    }
    for (int i = 0; i < a.size(); ++i) {
        a1.push(a[i]);
    }

    char ch = 'm';

    while (true) {
        if (ch == 'm') {
            ch = m1.front();
            m1.pop();
            if (m1.empty()) {
                cout << "M" << "\n";
                return;
            }
        }
        else if (ch == 'r') {
            ch = r1.front();
            r1.pop();
            if (r1.empty()) {
                cout << "R" << "\n";
                return;
            }
        }
        else if (ch == 'a') {
            ch = a1.front();
            a1.pop();
            if (a1.empty()) {
                cout << "A" << "\n";
                return;
            }
        }
    }
}
int32_t main() {

    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) zizo();
    return 0;
}
