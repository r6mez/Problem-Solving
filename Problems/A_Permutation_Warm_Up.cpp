/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Permutation Warm-Up
// URL: https://codeforces.com/contest/2108/problem/0
// Time: 5/1/2025, 5:42:16 PM
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

// void generate(){
//     for (int i = 1; i <= 10; i++){
//         vi a(i);
//         for (int j = 0; j < i; j++){
//             a[j] = j + 1;
//         }
        
//         set<int> dis;
//         do {
//             int sum = 0;
//             for (int j = 0; j < i; j++){
//                 sum += abs(a[j] - (j + 1));
//             }
//             dis.emplace(sum);
//         } while (next_permutation(all(a)));

//         cout << i << " " << dis.size() << "\n";
//     }
// }


void Ramez() {
    int n; cin >> n;
    int answer = (n*n) / 4 + 1;
    cout << answer << "\n";
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
    // generate();
    return 0;
}