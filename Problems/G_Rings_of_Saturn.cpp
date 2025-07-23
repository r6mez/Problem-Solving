/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// G. Rings of Saturn
// URL: https://codeforces.com/group/Rilx5irOux/contest/620530/problem/G
// Time: 7/18/2025, 5:32:33 PM
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
    vector<vi> rings(n, vi(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> rings[i][j];
        }
    }
    
    vector<multiset<int>> cols(m);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cols[i].insert(rings[j][i]);
        }
    }
 
    // sort the first column
    int k = 0;
    for(int x : cols[0]){
        rings[k][0] = x;
        k++;
    }
    
    
    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j++){
            auto it = cols[j].lower_bound(rings[i][j - 1]);
            if(it == cols[j].end()){
                cout << counter << "\n";
                return;
            } 
 
            rings[i][j] = *it;
            cols[j].erase(it);
        }
 
        counter++;
    }
    
    cout << counter << "\n";
}
 
/*
NOTES:
1 3 2
3 2 1
2 1 3
 
1 1 1
2 2 2
3 3 3
3
 
1 3 2
3 5 6
2 1 6
 
1 1 2
2 3 6
3 5 6
 
1 3 1
2 8 5 
4 10 6
 
1 3 5
2 8 1 
4 10 6
*/
 
int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}