/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Down with Brackets
// URL: https://codeforces.com/contest/2110/problem/B
// Time: 5/24/2025, 5:44:29 PM
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
    string s; cin >> s;
    int n = s.size();
    stack<char> st;

    int cnt = 0;
    for(char c : s){
        if(c == '(') {
            if(st.empty()) cnt++;
            st.push(c); 
            continue;
        }

        st.pop();
    }

    if(cnt > 1) cout << "YES\n";
    else cout << "NO\n";
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