/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Cost of the Array
// URL: https://codeforces.com/contest/2059/problem/B
// Time: 2/5/2025, 11:18:23 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;


void Ramez() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    if(k == n){
        int idx = 1;
        for (int i = 1; i < n; i+=2){
            if(a[i] != idx){
                cout << idx << "\n";
                return;
            } 
            idx++;
        }
        cout << idx << "\n";
    } else {
        for (int i = 1; i <= n-k+1; i++){
            if(a[i] != 1) {cout << 1 << "\n"; return;}
        }
        cout << 2 << "\n";
    }
}

/*
NOTES:
if k < n
    we can partition first part of b with two elements one of them is the answer
    n - k + 1 => first parition size 
5 4
1 1 1 2 2

5 4
1 1 | 1 | 2 | 2
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

