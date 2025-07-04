/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Pharmacy Simulator
// URL: https://codeforces.com/group/zJtqriSgdw/contest/616532/problem/E
// Time: 6/28/2025, 6:20:41 PM
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
    int n, m; cin >> n >> m;
    map<string, int> mn, mx;
    while(n--){
        string drug; int price; cin >> drug >> price;
        string prefix = drug.substr(0, 5);
        if(!mn[prefix]) mn[prefix] = INT_MAX;
        if(!mx[prefix]) mx[prefix] = INT_MIN;
        mn[prefix] = min(mn[prefix], price);
        mx[prefix] = max(mx[prefix], price);
    }

    int total = 0;
    while(m--){
        string rich, prefix; cin >> rich >> prefix;
        if(rich == "High") total += mx[prefix];
        else total += mn[prefix];
    }
    cout << total << "\n";
}

/*
NOTES:
1000000000000000000000020000000000000000000000500000000000000000000006000000000000000000000080000000000000000000000
100000000000000000000200000000000000000000300000000000000000000500000000000000000000900000000000000000000

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}