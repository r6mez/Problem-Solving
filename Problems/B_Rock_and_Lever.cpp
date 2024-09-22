// ﷽
// problem: B. Rock and Lever
// URL: https://codeforces.com/problemset/problem/1420/B  
// Start: 6/1/2024, 9:11:08 PM
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
using namespace std;
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

int largest_bit(int x) {
    return x == 0 ? -1 : 32 - __builtin_clz(x);
}

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;
    ll total = 0;
    vll freq(32, 0);
 
    for (int i = 0; i < n; i++) {
        int bitPos = largest_bit(a[i]);
        total += freq[bitPos]++;
    }
 
    cout << total << '\n';
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