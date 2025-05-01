/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Balance the Bits
// URL: https://codeforces.com/problemset/problem/1503/A
// Time: 4/23/2025, 8:52:41 PM
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

    int total1 = count(s.begin(), s.end(), '1');
    if (s[0] != '1' || s[n-1] != '1' || (total1 % 2) != 0) {
        cout << "NO\n";
        return;
    }

    string a(n, '-'), b(n, '-');
    int half1 = total1 / 2;
    int seen1 = 0;
    bool flip = false; // for zeros, alternate assignment
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            // First half of '1's -> '(', second half -> ')'
            if (seen1 < half1) {
                a[i] = b[i] = '(';
            } else {
                a[i] = b[i] = ')';
            }
            seen1++;
        } else {
            // s[i] == '0', assign opposite brackets alternately
            if (!flip) {
                a[i] = '(';
                b[i] = ')';
            } else {
                a[i] = ')';
                b[i] = '(';
            }
            flip = !flip;
        }
    }


    cout << "YES\n";
    cout << a << "\n" << b << "\n";
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