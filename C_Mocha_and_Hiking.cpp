// Ramez Medhat
// problem: C. Mocha and Hiking
// URL: https://codeforces.com/problemset/problem/1559/C  
// Start: 7/4/2024, 7:02:26 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi>& graph, vector<bool>& visited);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    if (a[0] == 1) {
        // Case where we can put n+1 at the beginning
        cout << n + 1 << " ";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    else if (a[n-1] == 0){
        // Case where we put n+1 at the end
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << n + 1 << "\n";
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 0; j <= i; ++j) {
                cout << j + 1 << " ";
            }
            cout << n + 1 << " ";
            for (int j = i + 1; j < n; ++j) {
                cout << j + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }

    cout << "-1\n";
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

