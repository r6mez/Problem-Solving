// ﷽
// problem: D. Line
// URL: https://codeforces.com/problemset/problem/1722/D  
// Start: 5/25/2024, 8:28:19 PM
#include <bits\stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                    tree_order_statistics_node_update>;
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


int n;

ll initialValue(string &s) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            sum += n - i - 1;
        } else {
            sum += i;
        }
    }
    return sum;
}

void solve() {
    cin >> n;
    string s; 
    cin >> s;
    
    ll sum = initialValue(s);
    vector<ll> gains;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            gains.push_back((n - 1 - i) - i);
        } else {
            gains.push_back(i - (n - 1 - i));
        }
    }

    sort(all(gains), greater<ll>());

    for (int k = 1; k <= n; ++k) {
        if (k - 1 < gains.size() && gains[k - 1] > 0) {
            sum += gains[k - 1];
        }
        cout << sum << " ";
    }
    cout << "\n";
}

/*
NOTES:
n men in line
-> L or R
-> each counts people in front of him

the value of the line = sum of all mens's counts

for each k in 1 to n 
we need to maximize the velue of the line 
-> you can change the direction of <= k people
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