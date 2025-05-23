/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. Dubstep
// URL: https://codeforces.com/problemset/problem/208/A
// Time: 2/12/2025, 12:43:49 PM
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
    string s; cin >> s;
    bool space = false;
    for (int i = 0; i < s.size(); ){
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 3;
            if(!space){
                cout << " ";
                space = true;
            }
        } else {
            cout << s[i];
            i++;
            space = false;
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

