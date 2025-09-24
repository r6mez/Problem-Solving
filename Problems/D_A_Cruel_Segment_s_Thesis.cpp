/*
    One day, I'm gonna grow wings
*/
// D. A Cruel Segment's Thesis
// URL: https://codeforces.com/contest/2140/problem/D
// Time: 9/9/2025, 7:05:48 PM
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
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    multiset<pii> f;
    multiset<pii> s;

    int sum = 0;
    for (int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        f.insert({l, r});
        s.insert({r, l});
        sum += r - l;
    }

    while (s.size() >= 2){
        auto [l1, r1] = *f.begin(); 
        auto [r2, l2] = *s.rbegin(); 
        f.erase(f.find({l1, r1}));  
        f.erase(f.find({l2, r2}));
        s.erase(s.find({r2, l2}));
        s.erase(s.find({r1, l1}));
        // cout << "added = " << r2 - l1 << "\n";
        sum += r2 - l1;
    }
    
    finish(sum);
}

/*
1 11 + 
2 7 
15 20 +
1 3 +
11 15 + 

1 20
1 15 

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}