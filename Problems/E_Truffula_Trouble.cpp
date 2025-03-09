/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// E. Truffula Trouble
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/E
// Time: 3/9/2025, 2:57:19 PM
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

    bool foundAnswer = false;

    int l = 0, r = 1e15;
    while(l + 1 < r){
        int mid = (l + r) / 2;
    
        // can ? 
        int d = mid, trees = 0;
        for (int i = 0; i < n; i++){
            if(trees >= k) break;
            if(d >= a[i]){
                d--;
                trees++;
                i++;
            } 
        }
        
        if(trees >= k) r = mid, foundAnswer = true;
        else l = mid;
    }
    
    if(!foundAnswer) r = -1;
    cout << r;
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