/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Koxia and Whiteboards
// URL: https://codeforces.com/problemset/problem/1770/A
// Time: 7/16/2025, 11:36:08 AM
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
    
    priority_queue<int, vi, greater<int>> pq;
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }

    vi b(m); cin >> b;
    
    for (int i = 0; i < m; i++){
        int mn = pq.top(); pq.pop();
        pq.push(b[i]);
    }
     
    
    int sum = 0;
    while(!pq.empty()){
        int mn = pq.top(); pq.pop();
        sum += mn;
    }
    
    cout << sum << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}