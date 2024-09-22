// ﷽
// problem: E. Secret Box
// URL: https://codeforces.com/contest/1985/problem/E  
// Start: 6/11/2024, 6:22:40 PM
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
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll maxVolume = 0;
    for (ll lengthIndex = 1; lengthIndex <= x; lengthIndex++)
    {
        for (ll widthIndex = 1; widthIndex <= y; widthIndex++)
        {
            if (k % (lengthIndex * widthIndex) == 0 && (k / (lengthIndex * widthIndex)) <= z)
            {
                maxVolume = max(maxVolume, (x - lengthIndex + 1) * (y - widthIndex + 1) * (z - (k / (lengthIndex * widthIndex)) + 1));
            }
        }
    }
    cout << maxVolume << "\n";
}

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