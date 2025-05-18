/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C1. Hacking Numbers (Easy Version)
// URL: https://codeforces.com/contest/2109/problem/C1
// Time: 5/17/2025, 6:41:15 PM
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

bool answer(){
    cout << "!" << "\n";
    cout.flush();
    int jury; cin >> jury;
    return jury == 1;
}

bool ask(string q){
    cout << q << "\n";
    cout.flush();
    int jury; cin >> jury;
    return jury == 1;
}


void Ramez() {
    int n; cin >> n;
    ask("mul 9");
    ask("digit");
    ask("digit");
    ask("add " + to_string(n - 9));    
    answer();
}

/*
NOTES:
we don't know x, we now the target y
we can do operation add, mul, div, and digit
but we can't know the result 

we can do digit, so it's 81
then binary search using the add command to get y
then use mul and add 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}