// Ramez Medhat
// problem: C - Maximum of n Integers
// URL: https://vjudge.net/contest/638602#problem/C  
// Start: 7/5/2024, 5:17:45 PM
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

void solve() {
    int n; cin >> n;
    vi a(n);
    map<int,int> freq;
    int maxx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
        freq[a[i]]++;
    }
    
    int lastMax = 0;
    for (int i = 0; i < n; i++){
        if(a[i] == maxx) lastMax = i+1;
    }
    

    if(freq[maxx] == 1){
        cout << n - lastMax + 1 << "\n";
    } else {
        cout << n - lastMax << "\n";
    }
}

/*
NOTES:
when i != k (correct answer)
else i == k (wrong answer)


find number of different k's which gives wrong answer

3
1 3 2
1 2 3 
2
k = 1 3,

if for the cell k we don't select as max (we set max = min previous)
if all the same = max, ans = 1

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
