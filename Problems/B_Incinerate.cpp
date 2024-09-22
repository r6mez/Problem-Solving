// ﷽
// problem: B. Incinerate
// URL: https://codeforces.com/problemset/problem/1763/B  
// Start: 6/7/2024, 3:56:14 PM
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
    for (const auto& i : v) os << i << ' ';
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; i++){
        cin >> monsters[i].second; 
    }
    for (int i = 0; i < n; i++){
        cin >> monsters[i].first; 
    }
    
    sort(all(monsters));

    int totalAlive = n;
    int min_power_index = 0;
    int min_power = 0;
    while (k > 0 && totalAlive > 0) {
        int alive = n;
        for (int i = 0; i < n; i++){
            monsters[i].second = max(0, monsters[i].second-k);
            if(monsters[i].second == 0) alive--;
            if (alive == 0) {totalAlive = 0; break;}
        }

        
        for(int i = min_power_index; i < n; i++) {
            if (monsters[i].second > 0) {
                min_power = monsters[i].first;
                min_power_index = i;
                break;
            }
        }
        k = max(0, k-min_power);
    }
    
    if(totalAlive > 0) cout << "NO\n";
    else cout << "YES\n";
}


/*
NOTES:
3 4
5 5 5
4 4 4

1 1 1
k = 5 - 4 = 1
0 0 0

*/

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