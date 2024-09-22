// ﷽
// problem: B. Choosing Cubes
// URL: https://codeforces.com/contest/1980/problem/B  
// Start: 6/3/2024, 5:48:25 PM
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
    int n, f, k; cin >> n >> f >> k;
    vi a(n); cin >> a;

    int favCube = a[f - 1];
    sort(a.begin(), a.end(), greater<int>());
    
    int favCount = count(all(a), favCube);
    int favInTopK = count(a.begin(), a.begin() + k, favCube);
    
    if(favInTopK == 0) {
        cout << "NO\n"; 
    } else if(favInTopK == favCount) {
        cout << "YES\n"; 
    } else {
        cout << "MAYBE\n";  
    }
}

/*
NOTES:
5 5 3
4 2 1 3 5


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