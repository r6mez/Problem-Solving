/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Knapsack
// URL: https://codeforces.com/problemset/problem/1446/A
// Time: 5/13/2025, 8:38:12 PM
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
    int n, w; cin >> n >> w;
    vector<pii> a(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = {x, i};
    }
    
    sort(all(a));

    for (int i = 1; i < n; i++){
        a[i].first += a[i - 1].first;
    }
    

    int l = 0, r = 0;
    while(r < n && l <= l){
        int sum = a[r].first - (l > 0? a[l - 1].first : 0);
        if(sum > w){
            l++; 
            continue;
        }
    
        if(sum < (w + 1) / 2){
            r++; 
            continue;
        }

        cout << r - l + 1 << "\n";
        for (int i = l; i <= r; i++){
            cout << a[i].second + 1 << " ";
        }
        cout << "\n";
        return;
    }

    cout << -1 << "\n";
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