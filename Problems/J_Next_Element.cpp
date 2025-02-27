/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// J. Next Element
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/263096/problem/J
// Time: 2/26/2025, 12:17:58 PM
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


    vi nextSmaller(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] >= a[st.top()]) {
            st.pop();
        }

        if (!st.empty()) {
            nextSmaller[i] = st.top();
        }

        st.push(i);
    }

    int q; cin >> q;
    while (q--) {
        int i; cin >> i;

        if(nextSmaller[i - 1] == -1){
            cout << "-1\n";
        } else {
            cout << nextSmaller[i - 1] + 1 << "\n";
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

