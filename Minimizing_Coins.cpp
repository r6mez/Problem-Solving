// Ramez Medhat
// problem: Minimizing Coins
// URL: https://cses.fi/problemset/task/1634  
// Start: 7/8/2024, 7:35:19 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi> &graph, vector<bool> &visited);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

void solve() {
    ll n; cin >> n;
    ll x; cin >> x;
    vll coins(n); cin >> coins;
    vll dp(x+1, 0);

    for (ll i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX;
        for(auto c : coins){
            if(i-c >= 0) {
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    
    if(dp[x] == INT_MAX) cout << -1;
    else cout << dp[x];
}

/*
NOTES:

coins
2 5 7

dp
0 1 2 3 4 1 2 3 4 2 3


*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

vector<vi> repGraph(int n, int m) {
    vector<vi> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return graph;
}

void dfs(int parent, vector<vi> &graph, vector<bool> &visited){
    if(visited[parent]) return;
    
    visited[parent] = true;
    for(int child : graph[parent]){
        dfs(child, graph, visited);
    }
}