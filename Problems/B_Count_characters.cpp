/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// B. Count characters
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/B
// Time: 2/15/2025, 3:15:41 PM
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
int MOD = 1000000007;

void Ramez() {
    string s; cin >> s;
    vi freq(200);
    
    for (int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }
    
    for (int i = 0; i < freq.size(); i++){
        if(freq[i] > 0){
            cout << char(i) << " " << freq[i] << "\n";
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

