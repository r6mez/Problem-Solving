/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Covered Points Count
// URL: https://codeforces.com/problemset/problem/1000/C
// Time: 5/15/2025, 2:33:20 PM
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
    int n; cin >> n;
    vector<pii> ps;
    for (int i = 0; i < n; i++){
        int in, out; cin >> in >> out;
        ps.push_back({in, 1});
        ps.push_back({out + 1, -1});
    }

    vi cnt(n);
    
    n = ps.size();
    sort(all(ps));

    int segs = 0;          
    for(int i = 0; i < n - 1; i++){
        segs += ps[i].second; 
        int x = ps[i].first;
        int next_x = ps[i+1].first;
        int len = next_x - x;
        if(segs > 0) {
            cnt[segs - 1] += len;
        }
    }

    cout << cnt;
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