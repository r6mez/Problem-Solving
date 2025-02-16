/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Aggressive cows
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/B
// Time: 2/10/2025, 10:44:41 PM
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

bool can(int d, int c, vi a){
    int usedCows = 1;
    int lastBarn = a[0];

    for (int i = 1; i < a.size(); i++){
        if(a[i] - lastBarn >= d){
            usedCows++;
            lastBarn = a[i];
        }

        if(usedCows >= c){
            return true;
        }
    }
    
    return false;
}

void Ramez() {
    int n, c; cin >> n >> c;
    vi a(n); cin >> a;
    sort(all(a));

    int l = 0, r = a[n-1] - a[0];

    while(l + 1 < r){
        int mid = (l+r)/2;
        if(can(mid, c, a)){
            l = mid;
        } else {
            r = mid;
        }
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

