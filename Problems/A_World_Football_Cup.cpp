/*
    One day, I'm gonna grow wings
*/
// A. World Football Cup
// URL: https://codeforces.com/problemset/problem/19/A
// Time: 10/7/2025, 8:48:12 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n; cin >> n;
    vector<string> names(n);
    cin >> names;
    map<string, array<int, 3>> mp;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        string teams, score;
        cin >> teams >> score;
        
        int dash = teams.find('-');
        string a = teams.substr(0, dash);
        string b = teams.substr(dash + 1);
        int colon = score.find(':');
        int x = stoi(score.substr(0, colon));
        int y = stoi(score.substr(colon + 1));


        if (x > y) mp[a][0] += 3;
        else if (x < y) mp[b][0] += 3;
        else mp[a][0]++, mp[b][0]++;

        mp[a][1] += x; mp[a][1] -= y;
        mp[b][1] += y; mp[b][1] -= x;

        mp[a][2] += x; mp[b][2] += y;
    }

    vector<array<variant<int, string>, 4>> res;
    for (auto& [team, arr] : mp) {
        int pts = arr[0];
        int diff = arr[1];
        int scored = arr[2];
        res.push_back({pts, diff, scored, team});
    }

    sort(all(res), greater<>());

    vector<string> winners;
    for (int i = 0; i < n / 2; i++) {
        winners.push_back(get<string>(res[i][3]));
    }

    sort(all(winners));
    for (auto& c : winners) {
        cout << c << "\n";
    }
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}