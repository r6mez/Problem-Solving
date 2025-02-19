/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. The first missing number
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/D
// Time: 2/18/2025, 9:49:50 PM
#include <bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#include <vector>
#define FAST std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    FAST
    long long n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;


    vector<pair<int, int>> freq(m + 1);
    for (int i = 0; i < n;i++) {
        if (a[i] > 0) freq[abs(a[i])].first += 1;
        else freq[abs(a[i])].second += 1;
    }

    for (int i = m; i >= 0; i--) {
        if (freq[i].second == 0) {
            cout << -i << endl;
            // break;
        }
    }
    
    for (int i = 1;i < m;i++) {
        break;
        if (freq[i].first == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
