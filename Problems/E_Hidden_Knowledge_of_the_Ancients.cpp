/*
    One day, I'm gonna grow wings
*/
// E. Hidden Knowledge of the Ancients
// URL: https://codeforces.com/contest/2149/problem/E
// Time: 9/25/2025, 6:20:53 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

int n, k, l, r;
vi a;

int calc(int currK){
    map<int, int> freq;
    int answer = 0;
    int x = 0, dis = 0;
    for (int y = 0; y < n; y++){
        if(freq[a[y]]++ == 0) dis++;
        while(dis > currK){
            freq[a[x]]--;
            if(freq[a[x]] == 0) dis--;
            x++;
        }
        answer += max(0LL, y - l - max(x, y - r + 1) + 2);
    }
    return answer;
}

void solve() {
    cin >> n >> k >> l >> r;
    a.resize(n);
    cin >> a;

    cout << calc(k) - calc(k - 1) << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}