// ﷽
// problem: B. Vanya and Lanterns
// URL: https://codeforces.com/problemset/problem/492/B  
// Start: 6/5/2024, 6:13:25 PM
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
#include <iomanip>
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
    int n, l;
    cin >> n >> l;
    vi a(n);
    cin >> a;
    sort(all(a));

    a.push_back(l+(l-a[n-1]));
    int maxDistance = a[0]*2;
    for (int i = 0; i < n; i++)
    {
        maxDistance = max(maxDistance, a[i+1]-a[i]);
    }

    cout << fixed << setprecision(10) << 0.5 * maxDistance << "\n";
}

/*
NOTES:
min d = 0.5 * max distance between any two lanterns
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