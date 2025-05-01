/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Chocolate Bunny
// URL: https://codeforces.com/problemset/problem/1407/C
// Time: 4/23/2025, 8:19:28 PM
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

int ask(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int x; cin >> x;
    return x;
}

void Ramez() {
    int n; cin >> n;
    vi a(n);
    int maxI = 1;
    for (int i = 2; i <= n; i++){
        int x = ask(maxI, i);
        int y = ask(i, maxI);
        if(x > y) {
            a[maxI - 1] = x;
            maxI = i;
        } else {
            a[i - 1] = y;
        }
    }

    a[maxI - 1] = n;
    
    cout << "! " << a << "\n";
}

/*
NOTES:
    if i ask about x y
    if x < y i get x
    if x >= y i get a number from 0 to y - 1

    if(a % b > b % a) then a < b


*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}