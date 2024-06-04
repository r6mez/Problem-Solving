// ﷽
// problem: A. Problem Generator
// URL: https://codeforces.com/contest/1980/problem/0  
// Start: 6/3/2024, 5:36:28 PM
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

void solve() {
    int n, m; 
    cin >> n >> m;
    string s; 
    cin >> s;


    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    

    int counter = 0;
    for (char level = 'A'; level <= 'G'; ++level) {
        if (freq[level] < m) {
            counter += (m - freq[level]);
        }
    }

    cout << counter << "\n";
}
/*
NOTES:
BGECDCBDED
A 0 
B 2
C 2
D 3
E 2
F 0
G 1
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