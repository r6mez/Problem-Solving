// ﷽
// problem: E. Making Anti-Palindromes
// URL: https://codeforces.com/problemset/problem/1822/E  
// Start: 5/4/2024, 7:56:48 AM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <numeric>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve() {
    ll n; string str;
    cin >> n >> str;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }

    //if char more than half!;

    ll f[26]{};
    for (int i = 0;i < n;i++)
    {
        if (++f[str[i] - 'a'] > n / 2)
        {
            cout << -1 << endl;
            return;
        }
    }


    ll left = 0, right = n - 1;

    ll fa[26]{};
    while (left < right)
    {
        if (str[left] == str[right])
        {
            fa[str[left] - 'a']++;
        }
        left++;
        right--;
    }

    cout << max((ll)(accumulate(fa, fa + 26, 0) + 1) / 2, *max_element(fa, fa + 26)) << endl;
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