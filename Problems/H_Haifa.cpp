/*
    I was alone in an empty universe.
    A universe too small and at the same time... too infinite.
*/
// H. Haifa
// URL: https://codeforces.com/group/Rilx5irOux/contest/538098/problem/H
// Time: 7/29/2025, 7:25:18 PM
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

    sort(all(a));

    vi b(n);
    int l = 0, r = n - k;
            
    for (int i = 0; i < n; i++){
        if(i % 2 == 0){
            b[i] = a[l];
            l++;
        } else {
            if(r < n){    
                b[i] = a[r];
                r++;
            } else {
                b[i] = a[l];
                l++;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 1; i < n - 1; i++){
        if(b[i - 1] < b[i] && b[i] > b[i + 1]){
            cnt++;
        }
    }
    
    if(cnt >= k) cout << b << "\n";
    else cout << "-1" << "\n";
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