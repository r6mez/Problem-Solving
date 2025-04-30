/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. awoo's Favorite Problem
// URL: https://codeforces.com/problemset/problem/1697/C
// Time: 4/29/2025, 8:03:45 PM
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
    string s, t; cin >> s >> t;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]){
            int o = i + 1;
            while (o < n && s[o] == s[i]){
                o++;
            }

            if (t[i] == s[o] && ((s[i] == 'a' && s[o] == 'b') || (s[i] == 'b' && s[o] == 'c'))){
                swap(s[i], s[o]);
            }
        }
    }

    if (s == t) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
we can move the a here abbbb to any position after it
we can move the b here bcccc to any position after it

abbabc
abbacb
babacb
bbaacb

bbaacb -> YES

bcaabababc
cbaabababc
cbbaaababc
cbbabaaabc
cbbababaac

cbbababaac



*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}