// ﷽
// problem: B. Large Addition
// URL: https://codeforces.com/contest/1984/problem/B  
// Start: 6/9/2024, 5:49:25 PM
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
    bool isPos = true;

    if (s[0] != '1') {
        isPos = false; 
    } else {
        for (int i = 1; i < s.size(); ++i) {
            if (i != s.size() - 1) {
                if (s[i] == '0') {
                    isPos = false;
                    break;
                }
            } else {
                if (s[i] == '9') {
                    isPos = false; 
                    break;
                }
            }
        }
    }

    if (isPos) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*
NOTES:
1337 yes
200 no
>= 100 not valid
< 100 not valid

1393938 yes
696969 >= valid

1434 yes 
717 >= valid 

98765432123456789 no
49382716061728400 4 not valid

11111111111111111
420
1984
10
69
119
59.5

55 + 55 = 110
5 + 5 = 10
5 + 6 = 11 
5 + 7 = 12
5 + 8
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