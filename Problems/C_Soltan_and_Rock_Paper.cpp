// ﷽
// problem: C - Soltan and Rock-Paper
// URL: https://vjudge.net/contest/632920#problem/C  
// Start: 6/7/2024, 6:09:41 PM
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
    string s; cin >> s;
    ll score = 0;

    for(int  i  = 0; i < s.size(); i++){
        if(i%2 == 1 && (s[i] == 'g'))
            score++;
        else if(i%2 == 0 && (s[i] == 'p'))
            score--;
    }

    cout << score << '\n';

}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}