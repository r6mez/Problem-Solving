/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Cherry Bomb
// URL: https://codeforces.com/contest/2106/problem/C
// Time: 4/24/2025, 4:50:27 PM
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
    vi a(n), b(n); cin >> a >> b;
    

    set<int> sums;
    int maxNotComp = -1;
    for (int i = 0; i < n; i++){
        if(b[i] != -1){
            sums.emplace(a[i] + b[i]);
        } 
    }
    
    
    if(sums.size() == 1) {
        int x = *sums.begin();
        for (int i = 0; i < n; i++){
            if(b[i] == -1){
                if(x - a[i] <= k && x - a[i] >= 0) continue;
                else {
                    cout << "0\n";
                    return;
                }
            }
        }
        cout << 1 << "\n";
    } else if (sums.size() > 1){
        cout << 0 << "\n";
    } else {
        int mx = *max_element(all(a));
        int maxSum = INT_MAX;
        for (int i = 0; i < n; i++){
            maxSum = min(maxSum, a[i] + k);
        }
        int answer = maxSum - mx + 1;
        cout << answer << "\n";
    }
}

/*
NOTES:
   1 3 2 5 4

5= 4 2 3 0 1
6= 
7=
8= 
9= 
10=


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}