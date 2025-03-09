/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D. Epic Transformation
// URL: https://codeforces.com/problemset/problem/1506/D
// Time: 3/6/2025, 4:23:29 PM
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
    vi a(n); cin >> a;
    
    map<int, int> freq;
    for (int x : a) freq[x]++;

    priority_queue<int> pq;
    for (auto &[num, count] : freq) pq.push(count);
    
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        first--; second--;
        if (first > 0) pq.push(first);
        if (second > 0) pq.push(second);
    }

    cout << (pq.empty() ? 0 : pq.top()) << '\n';
}

/*
NOTES:
1 1 1 1 2 2 3 3 4 4 

1 2 
1 2
1 3
1 4

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}