/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Dynamic Collection
// URL: https://codeforces.com/gym/104375/problem/D
// Time: 5/2/2025, 8:33:51 PM
#include <bits/stdc++.h>
#include <algorithm>
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

    sort(a.begin(), a.end());

    while(q--){
        int ops; cin >> ops;
        if(ops == 1){
            int k; cin >> k;
            auto it = lower_bound(all(a), k);
            if(it == a.end()) a.push_back(k), n++;
            else if(*it == k) continue;
            else {
                *it = k;
            }
        } else {
            // cout << a << "\n";
            int x, y; cin >> x >> y;
            // cout << x << " " << y << " : \n";
            int i = lower_bound(all(a), x) - a.begin(), j = upper_bound(all(a), y) - a.begin();
            int answer = j - i;
            cout << answer << "\n";
        }
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