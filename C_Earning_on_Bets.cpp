// ﷽
// problem: C. Earning on Bets
// URL: https://codeforces.com/contest/1979/problem/C  
// Start: 6/6/2024, 11:35:33 PM
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
    int n; cin >> n;
    vi k(n); cin >> k;
    
    int z = 1;
    for (int i = 0; i < n; i++) {
        z = lcm(z, k[i]);
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += z / k[i];
    }
    
    if (s < z) {
        for (int i = 0; i < n; i++) {
            cout << z / k[i] << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

/*
NOTES:
sum of bited numbers < smaller ai * x
3 2 7
3 + 2 + 7 = 12

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