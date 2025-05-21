/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// K. The median number
// URL: https://codeforces.com/group/Rilx5irOux/contest/607176/problem/K
// Time: 5/21/2025, 4:25:48 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("median.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    int n;cin >> n;
    vi arr(n); cin >> arr;

    multiset<int>st;
    multiset<int>::iterator it;

    for (int i = 0; i < n; ++i) {
        if (st.size() == 0) {
            if (arr[i] == -1) {
                cout << -1 << endl;
            }
            else {
                st.insert(arr[i]);
                it = st.begin();
            }
        }
        else {
            if (arr[i] == -1) {
                auto tmp = it;
                cout << *it << endl;
                // move it
                if (st.size() & 1) --it;
                else ++it;
                st.erase(tmp);
            }
            else {
                st.insert(arr[i]);
                int len = st.size();
                if ((len & 1) && arr[i] >= *it) ++it;
                if (!(len & 1) && arr[i] < *it) --it;
            }
        }
    }
}

/*
NOTES:

*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}