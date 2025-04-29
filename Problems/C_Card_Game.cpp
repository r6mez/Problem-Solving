/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Card Game
// URL: https://codeforces.com/contest/2104/problem/C
// Time: 4/28/2025, 6:18:11 PM
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

vector<vi> prefixSum2D(vector<vi>& a) {
    vector<vi> b(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        partial_sum(all(a[i]), b[i].begin());
    }
    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 1; j < a.size(); j++) {
            b[j][i] += b[j - 1][i];
        }
    }
    return b;
}

void Ramez() {
    int n; cin >> n;
    string s; cin >> s;

    vi a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a.push_back(i + 1);
        else b.push_back(i + 1);
    }

    for (int A : a) {
        bool BobWon = false;
        for (int B : b) {
            if(A == 1 && B == n) continue;
            if ((B == 1 && A == n) || (B > A)) {
                BobWon = true;
                break;
            }
        }

        if (BobWon == false) {
            cout << "Alice\n";
            return;
        }
    }

    cout << "Bob\n";
}

/*
NOTES:
BBBAAA
ABBAAB

ABAB
BBAA

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}