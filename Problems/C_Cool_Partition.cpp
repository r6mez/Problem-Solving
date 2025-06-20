/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Cool Partition
// URL: https://codeforces.com/contest/2117/problem/C
// Time: 6/8/2025, 5:51:59 PM
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
    vi a(n), freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; freq[a[i]]++;
    }

    vector<bool> inPrev(n + 1, 0), inCurr(n + 1, 0);
    vi prev, curr;

    int notSeen = 0, failed = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        freq[a[i]]--;

        if (freq[a[i]] == 0) failed++;

        if (!inCurr[a[i]]) {
            inCurr[a[i]] = 1;
            curr.push_back(a[i]);
            if (inPrev[a[i]]) {
                inPrev[a[i]] = 0;
                notSeen--;
            }
        }

        if (notSeen == 0 && failed == 0) {
            cnt++;
            notSeen = curr.size();
            
            prev.clear();
            for (int x : curr) {
                prev.push_back(x);
                inPrev[x] = 1;
                inCurr[x] = 0;      
            }
            curr.clear();
        }
    }

    if (!curr.empty()) cnt++;
    cout << cnt << "\n";
}


/*
NOTES:
(1 2) [1] (2 1) [2] [1 2]
[1 2] [1 2] [1 2] [1 2]

[5 8] [7 5 8] [5 7 8 10 9]

[1 2] [1 3 2] [1 3 2]
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}