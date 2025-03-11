/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. The Third Side
// URL: https://codeforces.com/contest/2074/problem/B
// Time: 3/11/2025, 4:43:07 PM
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
    sort(all(a));

    if(n == 1){
        cout << a[0] << "\n";
        return;
    }

    int curr = a[0] + a[1] - 1;
    for (int i = 2; i < n; i++){
        curr = curr + a[i] - 1;
    }
    
    cout << curr << "\n";
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