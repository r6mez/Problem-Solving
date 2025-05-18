/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Mafia
// URL: https://codeforces.com/problemset/problem/348/A
// Time: 5/16/2025, 4:09:23 PM
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

    function<bool(int)> can = [&](int x){
        int sum = 0;
        for (int i = 0; i < n; i++){
            if(a[i] > x) return false;
            sum += x - a[i];
        }
        
        return sum >= x;
    };

    int l = 1, r = 1;
    while(!can(r)) r *= 2;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
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