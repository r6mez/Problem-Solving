/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Pairs
// URL: https://codeforces.com/contest/1169/problem/B
// Time: 2/26/2025, 1:37:21 PM
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
    int n, m; cin >> n >> m;
    vi freq(n + 1); 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(a == b){
            freq[a]++;
        } else {
            freq[a]++;
            freq[b]++;
        }
    }
    
    map<int, int> zeyadLenguini;

    int countMiddle = 0;
    for (int i = 0; i < n + 1; i++){
        if(freq[i] == m){
            cout << "YES\n"; 
            return;
        }

        if(zeyadLenguini[freq[i]] != 0) zeyadLenguini[freq[i]] = i;
    }

    for(auto [f, i] : zeyadLenguini){
        if(f != m - f && zeyadLenguini.count(m - f)){
            cout << "YES\n"; 
            return;
        }
    }

    cout << "NO\n";
}

/*
NOTES:
two numbers that at least one of them appear in all pairs

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

