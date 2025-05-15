/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Quartet Swapping
// URL: https://codeforces.com/contest/2102/problem/D
// Time: 5/11/2025, 7:12:24 PM
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

    if(n == 4){
        if(a[0] > a[2]){
            swap(a[0], a[2]);
            swap(a[1], a[3]);
        }

        cout << a << "\n";
        return;
    }

    vi even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    sort(all(even), greater<>());
    sort(all(odd), greater<>());

    a.clear();

    for (int i = 0; i < n; i++) {
        if (i % 2 == 1 && !even.empty()) {
            a.push_back(even.back());
            even.pop_back();
        } else {
            a.push_back(odd.back());
            odd.pop_back();
        }
    }

    // reverse(all(a));

    cout << a << '\n';
}

/*
NOTES:
2 3 1 4
1 4 2 3


7 6 5 4 3 2 1
5 4 7 6 3 2 1
5 4 3 2 7 6 1
3 2 5 4 7 6 1

2 1 7 6 5 4 3
2 1 4 3 7 6 5


10 9 8 7 6 5 4 3 2 1
8 7 10 9 6 5 4 3 2 1
8 7 6 5 10 9 4 3 2 1
8 7 6 5 4 3 2 1 10 9
6 5 8 7 4 3 2 1 10 9
6 5 4 3 8 7 2 1 10 9
6 5 4 3 2 1 8 7 10 9
4 3 6 5 2 1 8 7 10 9
4 3 2 1 6 5 8 7 10 9
2 1 4 3 6 5 8 7 10 9


2 1 4 3 6 5 8 7 10 9
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}