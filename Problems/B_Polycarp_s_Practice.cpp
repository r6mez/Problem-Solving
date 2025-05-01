/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Polycarp's Practice
// URL: https://codeforces.com/problemset/problem/1006/B
// Time: 4/25/2025, 10:35:36 PM
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
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    vi b(a); sort(b.rbegin(), b.rend());
    vi freq(2001);
    int sum = 0;
    for (int i = 0; i < k; i++){
        freq[b[i]]++;
        sum += b[i];
    }

    cout << sum << "\n";

    int counter = 0;
    for (int i = 0; i < n; i++){
        if(k == 1) {
            cout << n - i << " ";
            break;
        } 

        counter++;
        if(freq[a[i]] > 0 && k > 1){
            k--;
            cout << counter << " ";
            counter = 0;
        } 

        freq[a[i]]--;
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