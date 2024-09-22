// ﷽
// problem: B. GCD Problem
// URL: https://codeforces.com/problemset/problem/1617/B  
// Start: 5/5/2024, 10:05:38 PM
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


void solve() {
    ll n; cin >> n;
    if (n % 2 == 0) cout << "2 " << (n - 3) << " 1\n";
    else {
        int cur = (n - 1) / 2;
        if (cur % 2 == 0) cout << cur - 1 << " " << cur + 1 << " " << 1 << endl;
        else cout << cur - 2 << " " << cur + 2 << " " << 1 << endl;
    }
}

/*
NOTES:
a + b + c = n
gcd(a,b) = c
c <= a,b

18
17/2 = 8 
7 9 1 


91 
45 
43, 47
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