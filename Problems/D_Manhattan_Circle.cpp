// ﷽
// problem: D. Manhattan Circle
// URL: https://codeforces.com/contest/1985/problem/D  
// Start: 6/11/2024, 6:06:12 PM
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    int firstTopM = -1, minFirstRightM = INT_MAX, firstRightN = 0;
    for (int i = 0; i < n; i++)
    {
        bool foundFirstRight = false;
        for (int j = 0; j < m; j++)
        {
            if(firstTopM == -1 && s[i][j] == '#') firstTopM = j;
            if(!foundFirstRight && s[i][j] == '#') {
                if (minFirstRightM > j){
                    minFirstRightM = j;
                    firstRightN = i;
                }
            }
        }
    }

    cout << firstRightN+1 << " " << firstTopM+1 << "\n";
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