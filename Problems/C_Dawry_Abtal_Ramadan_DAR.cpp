/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Dawry Abtal Ramadan (DAR)
// URL: https://codeforces.com/group/6aLUitEJUs/contest/590165/problem/C
// Time: 2/21/2025, 9:28:40 PM
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


bool comp(const pair<pair<int, pair<int, int>>, string>& a,
    const pair<pair<int, pair<int, int>>, string>& b) {
    if (a.first.first != b.first.first)
        return a.first.first > b.first.first;
    if (a.first.second.first != b.first.second.first)
        return a.first.second.first < b.first.second.first;
    return a.first.second.second < b.first.second.second;
}

void Ramez() {
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<pair<int, pair<int, int>>, string>> arr;

    for (int i = 0; i < n; i++) {
        string ss;
        getline(cin, ss);

        int sd, pnlt, wrg;
        cin >> sd >> pnlt >> wrg;
        cin.ignore();

        arr.push_back({ {sd, {pnlt, wrg}}, ss });
    }

    sort(arr.begin(), arr.end(), comp);

    cout << arr[0].second << endl;
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

