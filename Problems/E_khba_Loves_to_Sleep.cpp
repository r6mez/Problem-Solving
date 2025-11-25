/*
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⡴⢧⣀⠀⠀⣀⣠⠤⠤⠤⠤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⠏⢀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠈⠙⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢶⣶⣒⣶⠦⣤⣀⠀⠀    ██████╗  █████╗ ███╗   ███╗███████╗███████╗
⠀⠀⠀⠀⠀⠀⢀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣟⠲⡌⠙⢦⠈⢧⠀    ██╔══██╗██╔══██╗████╗ ████║██╔════╝╚══███╔╝
⠀⠀⠀⣠⢴⡾⢟⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡴⢃⡠⠋⣠⠋⠀    ██████╔╝███████║██╔████╔██║█████╗    ███╔╝                                            
⠐⠀⠞⣱⠋⢰⠁⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⢖⣋⡥⢖⣫⠔⠋⠀⠀⠀    ██╔══██╗██╔══██║██║╚██╔╝██║██╔══╝   ███╔╝  
⠈⠠⡀⠹⢤⣈⣙⠚⠶⠤⠤⠤⠴⠶⣒⣒⣚⣩⠭⢵⣒⣻⠭⢖⠏⠁⢀⣀⠀⠀⠀⠀    ██║  ██║██║  ██║██║ ╚═╝ ██║███████╗███████╗
⠠⠀⠈⠓⠒⠦⠭⠭⠭⣭⠭⠭⠭⠭⠿⠓⠒⠛⠉⠉⠀⠀⣠⠏⠀⠀⠘⠞⠀⠀⠀⠀    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢤⣀⠀⠀⠀⠀⠀⠀⣀⡤⠞⠁⠀⣰⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠘⠿⠀⠀⠀⠀⠀⠈⠉⠙⠒⠒⠛⠉⠁⠀⠀⠀⠉⢳⡞⠉⠀⠀⠀⠀⠀
                                
*/
// E. khba Loves to Sleep!
// URL: https://codeforces.com/problemset/problem/2167/E
// Time: 11/16/2025, 9:59:58 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    int n, k, x; 
    cin >> n >> k >> x;
    vi a(n); cin >> a;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = a.size();
    int l = 0, r = 1e9 + 5;
    while(l + 1 < r){
        int d = (l + r)/2;

        int a3r3r3r3rrr = max(a[0] - d + 1, 0LL) + max((x - a[n - 1] + 1) - d, 0LL);
        for (int i = 1; i < n; i++){
            int l = a[i] - a[i - 1] + 1;            
            a3r3r3r3rrr += max(l - 2 * d, 0LL);
        }
        if(a3r3r3r3rrr >= k) l = d;
        else r = d;
    }
    vi gumbull;
    int d = l;
    if(d == 0){
        for (int i = 0; i < k; i++){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if(max(a[0] - d + 1, 0LL)){
        for (int i = 0; i < max(a[0] - d + 1, 0LL) && gumbull.size() < k; i++){
            gumbull.push_back(i);
        }
    }
    for (int j = 1; j < n && gumbull.size() < k; j++){
        if(max((a[j] - a[j - 1] + 1) - 2 * d, 0LL)){
            for (int jj = a[j - 1] + d; jj <= a[j] - d && gumbull.size() < k; jj++){
                gumbull.push_back(jj);
            }
        }
    }    
    if(max((x - a[n - 1] + 1) - d, 0LL)){
        for (int i = a[n - 1] + d; i <= x && gumbull.size() < k; i++){
            gumbull.push_back(i);
        }
    }
    cout << gumbull << "\n";
}

/*
T T T T F F
0 1 2 3 4 5
*/

signed main() {
    // UseFile();
    FastIO();
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "TEST CASE " << i << "\n";
        solve(); 
    }
}