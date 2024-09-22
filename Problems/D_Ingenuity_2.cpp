// ﷽
// problem: D. Ingenuity-2
// URL: https://codeforces.com/contest/1974/problem/D  
// Start: 5/20/2024, 8:10:28 PM
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
    int n;
    string s;
    cin >> n >> s;

    string sol;
    map<char, char> who = { {'N', 'R'}, {'S', 'R'}, {'E', 'H'}, {'W', 'H'} };
    map<char, int> cnt;
    for (char c : s) {
        sol.push_back(who[c]);
        cnt[who[c]]++;
        who[c] = (who[c] == 'R' ? 'H' : 'R');
    }

    if (!cnt['R'] || !cnt['H'] || who['N'] != who['S'] || who['E'] != who['W']) {
        cout << "NO\n";
    }
    else {
        cout << sol << '\n';
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