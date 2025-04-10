/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// D. Skibidus and Sigma
// URL: https://codeforces.com/contest/2065/problem/D
// Time: 2/9/2025, 6:10:43 PM
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

int n = 10;

bool isSorted(vi &a){
    for (int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

bool noOnes(vi &a){
    for (int i = 0; i < n; i++){
        if(a[i] == 1) return false;
    }
    return true;
}

void construct(int i, vi a){
    if(i == n){
        if(noOnes(a)) return;

        vi copy(a);

        vector<pii> ops;
        
        while (true) {
            int lastZero = -1, firstOne = -1, lastOne = -1, firstTwo = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) lastZero = i;
    
                if (firstOne == -1 && a[i] == 1) firstOne = i;
                if (a[i] == 1) lastOne = i;
    
                if (firstTwo == -1 && a[i] == 2) firstTwo = i;
            }
    
            if (firstOne != -1 && firstOne < lastZero) {
                swap(a[firstOne], a[lastZero]);
                ops.push_back({ firstOne + 1, lastZero + 1 });
            }
            else if (lastOne != -1 && lastOne < lastZero) {
                swap(a[lastOne], a[lastZero]);
                ops.push_back({ lastOne + 1, lastZero + 1 });
            }
            else if (firstTwo != -1 && firstTwo < lastOne) {
                swap(a[firstTwo], a[lastOne]);
                ops.push_back({ firstTwo + 1, lastOne + 1 });
            } else break;
    
            // cout << a << "\n";
        }
    
        // cout << "\n" << a << "\n";
    
        cout << ops.size() << "\n";
        for (auto [u, v] : ops) {
            cout << u << " " << v << "\n";
        }
        
        return;
    }

    a[i] = 0;
    construct(i + 1, a);
    a[i] = 1;
    construct(i + 1, a);
    a[i] = 2;
    construct(i + 1, a);
}


void Ramez() {
    vi a(n, 0);
    construct(0, a);
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    // FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

