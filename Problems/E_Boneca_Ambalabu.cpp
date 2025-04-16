/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Boneca Ambalabu
// URL: https://codeforces.com/contest/2094/problem/E
// Time: 4/13/2025, 6:18:39 PM
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
    vi a(n); cin >> a;

    vi freqOn(30, 0), freqOff(30, 0);
    for (int i = 0; i < n; i++){
        for (int b = 0; b < 30; b++){
            if(a[i] & (1 << b)) freqOn[b]++;
            else freqOff[b]++;
        }
    }
    
    int maxCalc = -1;
    for (int i = 0; i < n; i++){
        int calc = 0;
        for (int b = 0; b < 30; b++){
            if(a[i] & (1 << b)) calc += (1 << b) * freqOff[b];
            else calc += (1 << b) * freqOn[b];
        }
        maxCalc = max(maxCalc, calc);
    }
    
    cout << maxCalc << "\n";
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