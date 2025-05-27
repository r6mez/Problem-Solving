/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Not Quite a Palindromic String
// URL: https://codeforces.com/contest/2114/problem/B
// Time: 5/26/2025, 5:42:11 PM
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
    int k; cin >> k;
    string s; cin >> s;
    int zeros = 0, ones = 0;
    for (int i = 0; i < n; i++){
        zeros += (s[i] == '0');
        ones += (s[i] == '1');
    }
     
    int minGood = abs(zeros - ones) / 2;

    if((k >= minGood) && ((k - minGood) % 2 == 0)) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
10 1
1101011001
1111110000
1 1

zeros = 4
ones = 6

k = 3 = 6
6 8
4 4

4 1
1011

z = 4 o = 8
k = 3
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}