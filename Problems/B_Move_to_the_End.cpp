/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Move to the End
// URL: https://codeforces.com/contest/2104/problem/B
// Time: 4/28/2025, 5:49:41 PM
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
    vi a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi suff(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = a[i] + suff[i + 1];
    }

    vector<pii> s;
    for (int i = 0; i < n; i++) {
        s.emplace_back(a[i], i);
    }

    sort(all(s));

    for (int k = 0; k <= n - 1; k++) {
        int idx = n - k;          

        while (!s.empty() && s.back().second >= idx) {
            s.pop_back();
        }

        cout << (suff[idx] + s.back().first) << ' ';
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