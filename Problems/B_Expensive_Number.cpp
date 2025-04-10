/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Expensive Number
// URL: https://codeforces.com/contest/2093/problem/B
// Time: 4/8/2025, 4:38:04 PM
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
    int mnI = 0, mn = 10;
    for (int i = s.size() - 1; i >= 0; i--){
        int digit = s[i] - '0';
        if(digit != 0){
            mnI = i;
            break;
        }
    }

    int count = s.size() - 1 - mnI;
    
    for (int i = 0; i < mnI; i++){
        if(s[i] != '0') count++;
    }
    
    cout << count << "\n";
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