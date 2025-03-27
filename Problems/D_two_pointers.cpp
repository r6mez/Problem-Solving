/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. two pointers
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/D
// Time: 3/13/2025, 1:47:47 AM
#include <bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#include <vector>
#define vi vector<int>
#define int  long long
int32_t main() {
    FAST
        int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = v[l] + v[r];
        if (sum > m) {
            r--;
        }
        else if (sum < m) l++;
        else {
            cout << (r - l) << endl;
            return 0;
        }
    }
}