// -------------------- Ramez -------------------------
// سَأَحمِلُ روحي عَلى راحَتي    وَأُلقي بِها في مَهاوي الرَدى
// فَإِمّـا حَــيــاةٌ تُسِــرُّ الـصَديقَ    وَإِمّــا مَمــاتٌ يُغــيظُ العِــدى
// ----------------------------------------------------
// problem: F. Mad Lab
// URL: https://codeforces.com/group/HcnH7vLzrr/contest/539291/problem/F  
// Start: 8/3/2024, 2:18:52 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <unordered_map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v)  v.begin(), v.end()
struct SegTree; const int MOD = 1000000007;
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template<typename T> istream& operator>>(istream& is, vector<T>& v);
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }


bool isSubsequence(string& s, string& t, ll n, ll m, ll k) {
    int j = 0, cnt = 0;
    for (int i = 0; i < n && j < m; ++i) {
        if (s[i] == t[j]) {
            cnt++;
            if (cnt >= k) {
                j++;
                cnt = 0;
            }
        }
    }
    return j == m;
}

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        ll l = 0, r = n / m;
        ll ans = 0;

        while (l <= r) {
            ll mid = (l + r) / 2;
            if (isSubsequence(s, t, n, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
NOTES:
2
0 2
*/