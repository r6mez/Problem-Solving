/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Max and Mod
// URL: https://codeforces.com/contest/2084/problem/0
// Time: 4/5/2025, 4:35:09 PM
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
    if(n % 2 == 0){
        cout << -1 << "\n";
        return;
    } else if (n == 3){
        cout << "3 2 1\n";
    } else {
        cout << n << " ";
        for (int i = 1; i < n; i++){
            cout << i << " ";
        }
        cout << "\n";
    }
}

/*
NOTES:
3
3 2 1

9
1 9 2 3 4 5 6 7 8

6 
1 6 2 3 4 5

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}