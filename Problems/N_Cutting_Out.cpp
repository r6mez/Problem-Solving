/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// N. Cutting Out
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/N
// Time: 3/11/2025, 3:08:52 PM
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

bool can(int k, int reqCopies, map<int, int> &freq){
    int counter = 0;
    for (auto [num, freq] : freq){
        counter += (freq / reqCopies);
    }
    return counter >= k;
}


void Ramez() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        freq[a[i]]++;
    }

    // we need to search for maximum valid number of copies 
    // that we can construct
    int l = 0, r = 2e5 + 10;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(k, mid, freq)) l = mid;
        else r = mid;
    }
    
    int counter = 0;
    for (auto [num, freq] : freq){
        for(int i = 0; i < freq / l; i++) {
            cout << num << " ";
            counter++;
            if(counter == k) return;
        }
    }
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