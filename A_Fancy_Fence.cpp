// ﷽
// problem: A. Fancy Fence
// URL: https://codeforces.com/contest/270/problem/A  
// Start: 5/29/2024, 6:32:23 PM
#include <bits\stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

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
    double angle;
    cin >> angle;
    for (double i = 3; ;i++)
    {
        double a = ((i - 2) * 180) / i;
        if (a == angle)
        {
            cout << "YES\n";
            return;
        }
        else if (a > angle)
        {
            cout << "NO\n";
            return;
        }
    }
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