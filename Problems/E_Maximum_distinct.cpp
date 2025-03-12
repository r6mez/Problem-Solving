/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Maximum distinct
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/E
// Time: 3/13/2025, 12:02:59 AM
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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    map<char, int> mp;

    for (int i = 0; i < k; i++){
        mp[s[i]]++;
    }

    int maxDistinct = mp.size();
    for (int i = 0; i < n - 1 - k; i++){
        mp[s[i + k]]++;

        mp[s[i]]--;
        if(mp[s[i]] == 0) mp.erase(s[i]);

        int currDistinct = mp.size();
        maxDistinct = max(maxDistinct, currDistinct);
    }
    
    cout << maxDistinct;
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