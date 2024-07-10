// Ramez Medhat
// problem: Removing Digits
// URL: https://cses.fi/problemset/task/1637  
// Start: 7/10/2024, 8:54:27 PM
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

vi getDigits(int n){
    vi digits;
    while(n != 0){
        digits.push_back(n%10);
        n /= 10;
    }
    return digits;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        vi digits = getDigits(i);
        for(auto digit : digits) {
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
}

/* Greedy (works)
int getBiggestDigit(int n){
    int digit = 0;
    while(n != 0){
        digit = max(digit, n%10);
        n /= 10;
    }
    return digit;
}

void solve() {
    int n; cin >> n;
    int ops = 0;
    while(n != 0){
        n -= getBiggestDigit(n);
        ops++;
    }
    cout << ops << "\n";
}
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