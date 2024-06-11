// ﷽
// problem: D - Soltan Formulas
// URL: https://vjudge.net/contest/632920#problem/D  
// Start: 6/7/2024, 5:51:19 PM
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

void solve(){
    string s; cin >> s;
    int n = s.length();
    ll sum = 0;

    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        ll cSum = 0;
        ll cNum = 0;

        for (int i = 0; i < n; ++i) {
            cNum *= 10;
            cNum += + (s[i] - '0');

            if ((mask & (1 << i)) || i == n - 1) {
                cSum += cNum;
                cNum = 0;
            }
        }

        sum += cSum;
    }

    cout << sum << "\n";
    
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}