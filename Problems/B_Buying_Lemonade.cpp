/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Buying Lemonade
// URL: https://codeforces.com/problemset/problem/2024/B
// Time: 5/4/2025, 10:08:13 PM
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
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    sort(all(a));

    function<bool(int)> can = [&](int m) -> bool {
        int sum = 0, last = 0;
        for (int i = 0; i <= m; i++){
            int added = (a[i] - last) * (n - i);
            if(sum + added >= k) return true;
            sum += added;
            last = a[i];
        }
        return false;
    };


    int l = -1, r = n;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }

    cout << k + r << "\n";
}

/*
NOTES:
1 3 6 7 
m = 2
sum = 4 + 6  


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}