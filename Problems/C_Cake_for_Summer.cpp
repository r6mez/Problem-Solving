/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// C. Cake for Summer
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/C
// Time: 1/27/2025, 12:25:26 PM
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
    int n, m, k; cin >> n >> m >> k;
    map<int, int> freq; 
    for (int i = 0; i < n*m; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int sum = 0, used = 0;
    for(auto [x, f] : freq){
        if(used < k){
            int added = min(k - used, f);
            used += added;
            sum += added * x;
        } else {
            break;
        }
    }
    
    cout << sum << "\n";
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

