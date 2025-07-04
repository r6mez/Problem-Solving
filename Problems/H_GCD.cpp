/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// H. GCD
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/H
// Time: 6/26/2025, 2:57:18 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;


int gcd(int a, int b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b){
    return (a * b)/gcd(a, b);
}


void Ramez() {
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << " " << lcm(a, b);
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}