/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// G. Every Letter of Stephen
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/G
// Time: 1/27/2025, 11:16:27 AM
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
    int n; cin >> n;

    vector<string> txt(n);

    cin >> txt;
    
    


    vi a(26); cin >> a;

    for (int i = 0; i < n; i++){
        map<char, int> x; 
        for (int j = 0; j < txt[i].size(); j++){
            x[txt[i][j]]++;
        }

        map<char, char> op;

        for(auto [c, f] : x){
            for (int k = 0; k < 26; k++){
                if(f == a[k]) {op[c] = char('a' + k); break;}
            }
        }

        for (int j = 0; j < txt[i].size(); j++){
            if(!iswalnum(txt[i][j])) txt[i][j] = op[txt[i][j]];
        }
    }
    
    cout << txt;
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

