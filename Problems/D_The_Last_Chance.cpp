/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. The Last Chance
// URL: https://codeforces.com/group/zJtqriSgdw/contest/616532/problem/D
// Time: 6/28/2025, 7:37:26 PM
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
    map<string, string> codes = {
        {"000", "AND"},
        {"001", "ADD"},
        {"010", "LDA"},
        {"011", "STA"},
        {"100", "BUN"},
        {"101", "BSA"},
        {"110", "ISZ"},
    };

    string s;
    
    while (cin >> s) {
        string op = s.substr(1, 3), add = s.substr(4, 12);
        stringstream hexAddress;
        hexAddress << hex << uppercase << setfill('0') << setw(3) << stoul(add, nullptr, 2);        
        string addressHex = hexAddress.str();
        cout << codes[op] + " " + addressHex << endl;
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