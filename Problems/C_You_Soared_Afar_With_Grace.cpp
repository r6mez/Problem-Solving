/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. You Soared Afar With Grace
// URL: https://codeforces.com/contest/2084/problem/C
// Time: 4/5/2025, 5:08:29 PM
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

void updateMap(map<pii, int>& mp, int idx, int a_val, int b_val) {
    mp[{a_val, b_val}] = idx;
}

void Ramez() {
    int n; cin >> n;
    vi a(n), b(n); cin >> a >> b;
    map<pii, int> ps;

    int countDups = 0;
    int dupNumber = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) countDups++, dupNumber = a[i];
        ps[{a[i], b[i]}] = i;
    }

    if ((n % 2 == 1 && countDups != 1)  || (n % 2 == 0 && countDups > 0)) {
        cout << -1 << "\n";
        return;
    }

    vector<pii> ops;

    if (n % 2 == 1) {
        int j = ps[{dupNumber, dupNumber}];
        int k = n / 2;
        if (j != k) {
            ops.push_back({ j, k });
            swap(a[j], a[k]);
            swap(b[j], b[k]);
            ps[{a[j], b[j]}] = j;
            ps[{a[k], b[k]}] = k;
            
        }
    }

    for (int i = 0; i < n / 2; i++) {
        if (!ps.count({ b[i], a[i] })) {
            cout << -1 << "\n";
            return;
        }

        int j = n - 1 - i;
        int k = ps[{b[i], a[i]}];

        if (a[i] == b[j] && b[i] == a[j]) continue;

        ops.push_back({ j, k });
        swap(a[j], a[k]);
        swap(b[j], b[k]);
        ps[{a[j], b[j]}] = j;
        ps[{a[k], b[k]}] = k;
    }

    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i].first + 1 << " " << ops[i].second + 1 << "\n";
    }
}

/*
NOTES:
2 5 1 3 4
3 5 4 2 1

1 2 5 3 4
4 3 5 2 1

if n is even, no a[i] == b[i] allowed
if odd a[i] == b[i] for more than 2 indices,
answer is -1


1 3 2 4
2 4 1 3

1 2 3 4
2 1 4 3 X

1 3 4 2
2 4 3 1

1 3 2 4
2 4 1 3

1 3 4 2
2 4 3 1


5
2 5 1 3 4
3 5 4 2 1

2 1 5 4 3
3 4 5 1 2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}