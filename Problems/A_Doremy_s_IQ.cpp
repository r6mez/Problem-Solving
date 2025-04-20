/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Doremy's IQ
// URL: https://codeforces.com/problemset/problem/1707/A
// Time: 4/20/2025, 10:07:17 PM
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
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    int count = 0;

    string s(n, '0');
    for (int i = n - 1; i >= 0; i--){
        if(a[i] <= count){
            s[i] = '1';
        } else if (count < q){
            s[i] = '1';
            count++;
        }        
    }
    
    cout << s << "\n";
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