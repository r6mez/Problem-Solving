// ﷽
// problem: D - Soltan and Beautiful Strings
// URL: https://vjudge.net/contest/631754#problem/D  
// Start: 5/31/2024, 5:55:20 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
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
    map<char,int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }

    for(auto [c,f]: m){
        if(f%2==1){
            cout << "No";
            return;
        }
    }

    cout << "Yes";
    
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