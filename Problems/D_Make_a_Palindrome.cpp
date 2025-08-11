/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// D. Make a Palindrome
// URL: https://codeforces.com/problemset/problem/2124/D
// Time: 7/23/2025, 2:30:54 PM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
    vi sortedA = a, copyA;
    sort(all(sortedA));

    int x = sortedA[k - 1], counter = (upper_bound(all(sortedA), x) - a.begin()) - 1;

    for (int i = 0; i < n; i++) if(a[i] <= x) copyA.push_back(a[i]);
    a = copyA;

    int l = 0, r = a.size() - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            l++; r--;
            continue;
        }

        if(counter < k){
            cout << "NO\n";
            return;
        }

        if (a[l] == x) {
            counter--;
            l++;
        } else if (a[r] == x) {
            counter--;
            r--;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}