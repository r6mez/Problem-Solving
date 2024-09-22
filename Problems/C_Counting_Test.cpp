// ﷽
// problem: C. Counting Test
// URL: https://codeforces.com/group/isP4JMZTix/contest/386415/problem/C  
// Start: 4/28/2024, 11:41:47 AM
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
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve()
{
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<ll>> freq(26, vector<ll>(n + 1, 0));
    for (ll i = 1; i < n + 1; i++)
    {
        freq[s[i - 1] - 'a'][i]++;
    }
    for (ll i = 0; i < 26; i++)
        for (ll j = 1; j < n + 1; j++)
            freq[i][j] += (freq[i][j - 1]);
    for (ll i = 0; i < q; i++)
    {
        ll ans = 0;
        ll l, r;
        char c;
        cin >> l >> r >> c;
        l--;
        ll x = l / n;
        ll y = r / n;
        l %= n;
        r %= n;
        x = (x * freq[c - 'a'][n]) + freq[c - 'a'][l];
        y = (y * freq[c - 'a'][n]) + freq[c - 'a'][r];
        cout << y - x << endl;
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