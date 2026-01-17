/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Aliases
// URL: https://codeforces.com/gym/104375/problem/A
// Time: 5/2/2025, 8:25:44 PM
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
    map<string, int> freq;
    while(n--){
        int x; cin >> x;
        string name = "";
        while(x--){
            string word; cin >> word;
            name += word[0];
        }    
        freq[name]++;
    }
    
    int counter = 0;
    for(auto [name, f] : freq){
        if(f == 1) counter++;
    }

    cout << counter;
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