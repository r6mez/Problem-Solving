/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Prinzessin der Verurteilung
// URL: https://codeforces.com/problemset/problem/1536/B
// Time: 6/10/2025, 10:54:48 PM
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
    string s; cin >> s;

    set<string> st;
    for (int i = 0; i < n; i++) {
        string x = { s[i] };
        st.insert(x);
    }

    for (int i = 0; i < n - 1; i++) {
        string x = { s[i], s[i + 1] };
        st.insert(x);
    }

    for (int i = 0; i < n - 2; i++) {
        string x = { s[i], s[i + 1], s[i + 2] };
        st.insert(x);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        string x = { c, };
        if (st.find(x) == st.end()) {
            cout << x << "\n";
            return;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string x = { c, j };
            if (st.find(x) == st.end()) {
                cout << x << "\n";
                return;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string x = { c, j, k };
                if (st.find(x) == st.end()) {
                    cout << x << "\n";
                    return;
                }
            }
        }
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