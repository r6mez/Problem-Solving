// Ramez Medhat
// problem: B. Angry Monk
// URL: https://codeforces.com/contest/1992/problem/B  
// Start: 7/11/2024, 5:46:01 PM
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
const int MOD = 1000000007;
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
    int n, k; cin >> n >> k;
    vi a(k);
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    
    sort(all(a));

    ll ops = 0;
    for (int i = 0; i < k-1; i++){
        ops += (2*a[i] - 1);
    }

    cout << ops << "\n";
}

/*
NOTES:
6
5 1
4 1 
3 1 
2 1
1 1
x - 1 + x
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