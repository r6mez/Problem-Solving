/*
    One day, I'm gonna grow wings
*/
// D. Minimal Height Tree
// URL: https://codeforces.com/problemset/problem/1437/D
// Time: 8/20/2025, 7:07:18 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> auto& operator<<(auto& o, vector<T>& v) { for (auto& e : v) o << e << ' '; return o; }
template<typename T> auto& operator>>(auto& i, vector<T>& v) { for (auto& e : v) i >> e; return i; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;


    queue<pii> q;
    int h = 1;
    bool newParent = true;
    pii currParent = {1, 1};

    for (int i = 1; i < n - 1; i++){
        q.push({a[i], currParent.second + 1});
        
        if(a[i] > a[i + 1]){
            currParent = q.front(); q.pop();
        }
    }

    cout << currParent.second << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}