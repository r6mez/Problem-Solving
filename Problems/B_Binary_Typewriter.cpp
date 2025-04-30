/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Binary Typewriter
// URL: https://codeforces.com/contest/2103/problem/B
// Time: 4/21/2025, 9:44:24 PM
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
    
    int press = 1, flip = 0;
    if(s[0] == '1') flip++;
    for (int i = 1; i < n; i++){
        if(s[i] != s[i - 1]) flip++;
        press++;
    }
    
    if(flip == 2) flip -= 1;
    if(flip > 2) flip -= 2;
    int answer = press + flip;
    cout << answer << "\n";
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