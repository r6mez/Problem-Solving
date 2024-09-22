// Ramez Medhat
// problem: Dice Combinations
// URL: https://cses.fi/problemset/task/1633  
// Start: 7/8/2024, 6:52:08 PM
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

const int mod = 1e9 + 7;
vector<int> dp;

int calc(int n) {
    if (n == 0) return 1;   
    if (dp[n] != -1) return dp[n];

    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        if (n - i >= 0) {
            ways = (ways + calc(n - i)) % mod;
        }
    }

    dp[n] = ways;
    return dp[n];
}

void solve() {
    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    int ways = calc(n);
    cout << ways << "\n";
}
/*
NOTES:
3 
 1 1 1 
 1 2 
 2 1 
 3 

 4
 1 1 1 1
 1 1 2 
 1 2 1
 1 3 
 2 1 1
 2 2 
 3 1 
 4 

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