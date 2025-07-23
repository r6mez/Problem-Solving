/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D2. Balance (Hard version)
// URL: https://codeforces.com/contest/1732/problem/D2
// Time: 7/16/2025, 1:43:02 PM
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
    int t; cin >> t;
    set<int> exist;
    map<int, int> mex;
    map<int, set<int>> multiples, deleted;
    exist.insert(0);
    while (t--) {
        string s; cin >> s;
        if (s == "+") {
            int x; cin >> x;
            for (int i : multiples[x]) deleted[i].erase(x);
            exist.insert(x);
        } else if (s == "?") {
            int k; cin >> k;
            while(exist.count(mex[k])) { 
                multiples[mex[k]].insert(k);
                mex[k] += k;
            }

            if(deleted[k].empty()) cout << mex[k] << "\n"; 
            else cout << min(mex[k], *deleted[k].begin()) << "\n";
        } else {
            int x; cin >> x;
            for (int i : multiples[x]) deleted[i].insert(x);
            exist.erase(x);
        }
    }
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