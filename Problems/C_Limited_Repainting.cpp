/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Limited Repainting
// URL: https://codeforces.com/contest/2070/problem/C
// Time: 2/27/2025, 6:03:14 PM
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

// Function to check if we can achieve a maximum penalty of at most `mid` with `k` operations
bool canAchieve(string &s, vector<int> &penalties, int k, int mid) {
    int n = penalties.size();
    bool isColoring = false;  // Tracks if we are currently in a painted segment

    for (int i = 0; i < n; ++i) {
        if (penalties[i] > mid) { // If the penalty is too high, we must fix it
            if (isColoring && s[i] == 'R') {
                isColoring = false;  // Stop coloring when we reach a red cell
            } else if (!isColoring && s[i] == 'B') {
                if (k == 0) return false;  // No more operations left
                k--;  
                isColoring = true;
            }
        }
    }
    return true;
}

void Ramez() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> penalties(n); cin >> penalties;

    int lo = 0, hi = 1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canAchieve(s, penalties, k, mid)) {
            hi = mid;  
        } else {
            lo = mid + 1; 
        }
    }

    cout << lo << "\n";  
}

/*
NOTES:
10 2
B R B R B B R R B R
5 1 2 4 5 3 6 1 5 4

maxB = 5;
maxR = 6;

5 (1) 2 (4) 5 (6) 5 4

B B B B B B R R B R
5 1 2 4 5 3 6 1 5 4

RRRRR
5 3 1 2 4

get segments of B, get maximum number in each one

get maximum number of R between them

we can color X conseq B segments if the max red between > max B in them
otherwise it would create another heigher penalty

if k == number of B segments, answer = 0;

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

