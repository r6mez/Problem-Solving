// ﷽
// problem: A - Shaarawy and The Unbalanced String
// URL: https://vjudge.net/contest/631754#problem/A  
// Start: 5/31/2024, 5:30:33 PM
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
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
    }

    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == s[i + 1] || s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << endl;
            return;
        }
    }

    cout << "-1 -1" << endl;
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