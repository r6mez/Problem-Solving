/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Tung Tung Sahur
// URL: https://codeforces.com/contest/2094/problem/D
// Time: 4/13/2025, 5:58:06 PM
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
    string p, s; cin >> p >> s;
    int n = p.size(), m = s.size();
    int i = 0, j = 0;
    
    while(true){
        if(i >= n || j >= m) break;
        char curr = p[i];

        if (p[i] != s[j]) {
            cout << "NO\n";
            return;
        }

        int countP = 1, countS = 1;
        j++, i++;
        while(i < n && p[i] == curr) countP++, i++;
        while(j < m && s[j] == curr) countS++, j++;

        // cout << countP << " " << countS << "\n";
        if(countP <= countS && countS <= countP * 2) continue;
        else {
            cout << "NO\n";
            return;
        }
    }
    
    if (i == n && j == m) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
LLL
LLL
LLLL
LLLLL
LLLLLL
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}