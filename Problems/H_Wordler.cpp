/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// H. Wordler
// URL: https://codeforces.com/group/zJtqriSgdw/contest/616532/problem/H
// Time: 6/28/2025, 6:51:52 PM
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
    string word = "THEME";
    string s; cin >> s;
    int n = word.size();

    map<char, int> cnt;
    for (char c : word) cnt[c]++;
    vector<string> result(n, "a333");

    for (int i = 0; i < n; i++) {
        if (s[i] == word[i]) {
            result[i] = "GREEN";
            cnt[s[i]]--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (result[i] != "a333") continue;  
        if (cnt[s[i]]) {
            result[i] = "YELLOW";
            cnt[s[i]]--;
        } else {
            result[i] = "GREY";
        }
    }

    cout << result;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}