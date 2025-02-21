/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D - Removing Digits
// URL: https://vjudge.net/contest/694790#problem/D
// Time: 2/21/2025, 3:24:16 PM
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

int getMaxDigit(int n){
    int maxDigit = 0;
    while(n != 0){
        maxDigit = max(maxDigit, n%10);
        n /= 10;
    }
    return maxDigit;
}

void Ramez() {
    int n; cin >> n;
    int steps = 0;
    while(n != 0) {
        n -= getMaxDigit(n);
        steps++;
    }
    cout << steps << "\n";
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

