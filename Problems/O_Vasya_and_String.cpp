/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// O. Vasya and String
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/O
// Time: 3/11/2025, 3:41:44 PM
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

bool can(int reqBeauty, int n, int k, string &s, vi &freqA, vi &freqB){
    for (int i = 0; i < n; i++){
        int j = min(n - 1, i + reqBeauty - 1);
        if(s[i] == 'a'){
            int sumA = freqA[j] - (i > 0? freqA[i - 1] : 0);
            if(sumA + k >= reqBeauty) return true;
        } else {
            int sumB = freqB[j] - (i > 0? freqB[i - 1] : 0);
            if(sumB + k >= reqBeauty) return true;
        }
    }
    return false;
}

void Ramez() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    vi freqA(n), freqB(n);
    for (int i = 0; i < n; i++){
        freqA[i] += (s[i] == 'a');
        freqB[i] += (s[i] == 'b');
    }

    partial_sum(all(freqA), freqA.begin());
    partial_sum(all(freqB), freqB.begin());

    int l = 0, r = n+1;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(can(mid, n, k, s, freqA, freqB)) l = mid;
        else r = mid;
    }
    
    cout << l;
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