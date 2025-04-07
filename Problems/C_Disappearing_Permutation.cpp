/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Disappearing Permutation
// URL: https://codeforces.com/contest/2086/problem/C
// Time: 4/3/2025, 5:02:43 PM
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
    vi p(n + 1), d(n); 
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    cin >> d;

    vi ops(n), vis(n + 1);
    for (int i = 0; i < n; i++){
        if(i != 0) ops[i] = ops[i - 1];
        int pointer = d[i];
        if(!vis[pointer] && p[pointer] == pointer) ops[i]++;
        vis[pointer] = true;
        while(p[pointer] != pointer){
            int newPointer = p[pointer];
            p[pointer] = pointer;
            pointer = newPointer;
            ops[i]++;
            vis[pointer] = true;
        }
    }
    
    cout << ops << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}