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
    int mx = INT_MIN, k = -1;
    vi pre(n); pre[0] = a[0]; 
    vi suf(n); suf[n - 1] = a[n - 1]; 
    
    for (int i = 1; i < n - 1; i++){
        mx = max(mx, a[i]);
    }
    
    for (int i = 1; i < n; i++){
        pre[i] = max(a[i], pre[i - 1]);
    }

    
    for (int i = n - 2; i >= 0; i--){
        suf[i] = max(a[i], suf[i + 1]);
    }

    int a33 = INT_MAX;
    for (int i = 1; i < n - 1; i++){
        a33 = min(a33, a[i] + pre[i - 1] + suf[i + 1]);
        // cout << i << " " << a33 << "\n";
    }
    

    int answer = min(a33, mx + a[0] + a[n - 1]);
    cout << answer << "\n";
}

/*
NOTES:
5
101 <- original
100 <- remove 1
011 <- remove 2
010 <- remove 3

2
010

first
110
1110

second
110
0111

first
110
0100

second
100
0100

player 
n bit 


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}