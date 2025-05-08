/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Apples in Boxes
// URL: https://codeforces.com/contest/2107/problem/B
// Time: 5/5/2025, 11:23:02 PM
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
    sort(all(a));

    int diff = a[n - 1] - a[0];

    if(diff - 1 > k || (diff > k && a[n - 1] == a[n - 2])){
        cout << "Jerry\n";
        return;
    }

    int sum = accumulate(all(a), 0LL);

    if(sum%2 == 1) cout << "Tom\n";
    else cout << "Jerry\n";
}

/*
NOTES:
if odd tom wins
if even jerry wins 

if odd 
    jerry tries to make the differene > k 
if even
    tom tries to make the differene > k 


you can't make it more than K unless it is that at the beggining

1 3 3 
1 2 3 t
1 2 2 j
1 1 2 t
1 1 1 j
1 1 0 t
1 0 0 j
0 0 0 t
0 0 0 j -> looses, but how can he win ???

1 3 3 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}