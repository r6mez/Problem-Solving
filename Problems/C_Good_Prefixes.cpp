// ﷽
// problem: C. Good Prefixes
// URL: https://codeforces.com/contest/1985/problem/C  
// Start: 6/11/2024, 5:47:50 PM
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
    int n; cin >> n;
    vll a(n); cin >> a;
    ll maxi = 0, sum = 0;
    int counter = 0;
    for (int i = 0; i < n; i++){
        if(maxi <= a[i]){
            sum += maxi;
            maxi = a[i];
        } else {
            sum += a[i];
        }
        if(sum == maxi) counter++;
    }
    cout << counter << "\n";
}

/*
NOTES:
4
1 1 2 0
2 2
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