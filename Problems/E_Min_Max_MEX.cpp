/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// E. Min Max MEX
// URL: https://codeforces.com/contest/2093/problem/E
// Time: 4/8/2025, 5:45:51 PM
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
    vi a(n); cin >> a;

    int l = 0, r = 2e5 + 1;
    while(l + 1 < r){
        int m = (l + r)/2;

        int subs = 0;
        set<int> s;
        for (int i = 0; i < n; i++){
            if(a[i] < m) s.insert(a[i]);

            if(s.size() == m) {
                subs++;
                s.clear();
            }
        }
        

        if(subs >= k) l = m;
        else r = m;
    }

    cout << l << "\n";
}

/*
NOTES:
2 1 0 0 1 2
0 0 3 3 3 3

0 0 0 0 0
1 1 1 1 1

2 3 4 5 6
0 0 0 0 0 

0 0 1 1 2 2
1 1 2 2 3 3

1 0 0 0
0 1 1 1 


9 3
0 1 2 0 1 2 0 1 2
1 2 3 3 3 3 3 3 3

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}