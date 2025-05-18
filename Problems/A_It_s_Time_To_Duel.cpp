/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. It's Time To Duel
// URL: https://codeforces.com/contest/2109/problem/0
// Time: 5/17/2025, 5:39:02 PM
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
    vi a(n);
    int zeros = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        zeros += (a[i] == 0);
    }
    
    if(zeros == 0) {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n - 1; i++){
        if (a[i] == a[i + 1] && a[i] == 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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