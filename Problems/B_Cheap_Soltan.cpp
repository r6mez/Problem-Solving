// Ramez Medhat
// problem: B - Cheap Soltan
// URL: https://vjudge.net/contest/638602#problem/B  
// Start: 7/5/2024, 5:47:03 PM
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
    vll a(n);
    ll minCost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minCost += a[i];
    }
    

    if(n == 1)  cout << a[0] << " " << a[0] << "\n"; 
    else
    {
        int maxSize = a[0];
        for (int i = 0; i < n-1; i++){
            maxSize = gcd(maxSize, a[i+1]);
        }
        cout << minCost << " " << maxSize << "\n";
    }
}

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


