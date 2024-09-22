// ﷽
// problem: C. Train and Queries
// URL: https://codeforces.com/problemset/problem/1702/C  
// Start: 5/24/2024, 3:31:32 PM
#include <bits\stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
 
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>>m;
    for (int i = 0; i < n; i++){
        int u;
        cin >> u;
        if(!m.count(u)) {
            m[u].first = i;
            m[u].second = i;
        }
        else m[u].second = i;
    }
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        if(!m.count(a) || !m.count(b) || m[a].first > m[b].second) {
            cout << "NO\n"; 
        }
        else cout << "YES\n";
    }
} 

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}