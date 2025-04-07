/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Penalty
// URL: https://codeforces.com/contest/1553/problem/C
// Time: 4/3/2025, 12:48:18 PM
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
    int aKicks = 0, bKicks = 0;
    int aRealGoals = 0, bRealGoals = 0;
    int aMaxGoals = 0, bMaxGoals = 0; 

    for (int i = 0; i < 10; i++){
        if((i + 1)%2) { // a turn
            if(s[i] == '1' || s[i] == '?') aMaxGoals++;
            if(s[i] == '1') aRealGoals++;
            aKicks++;
        } else { // b turn
            if(s[i] == '1' || s[i] == '?') bMaxGoals++;
            if(s[i] == '1') bRealGoals++;
            bKicks++;
        }

        if((aMaxGoals - bRealGoals > (5 - bKicks)) || (bMaxGoals - aRealGoals > (5 - aKicks))) {
            cout << i + 1 << "\n";
            return;
        }
    }
    
    cout << 10 << '\n';
}

/*
NOTES:
1?0???1001
1000101
3-0
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}