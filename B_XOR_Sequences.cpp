// ﷽
// problem: B. XOR Sequences
// URL: https://codeforces.com/contest/1979/problem/B  
// Start: 6/6/2024, 11:13:09 PM
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
    int a, b; cin >> a >> b;
    bitset<32> x(a), y(b); 
    int c = 0;
    for (int i = 0; i < 32; i++){
        if(x[i] != y[i]) break;
        c++;
    }
    cout << (1 << c) << "\n";
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