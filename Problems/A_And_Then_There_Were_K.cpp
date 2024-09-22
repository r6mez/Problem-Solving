// ﷽
// problem: A. And Then There Were K
// URL: https://codeforces.com/problemset/problem/1527/A  
// Start: 6/1/2024, 8:24:48 PM
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
    int lastBit;
    int lastBitPos=0;
    for(int i=0; i<30; ++i)
    {
        if(((n>>i)&1) == 1)
        {
            lastBitPos=i;
        }
    }
    cout<<(1<<lastBitPos)-1<<"\n";
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