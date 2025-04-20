/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Friends and Gifts
// URL: https://codeforces.com/problemset/problem/1283/C
// Time: 4/20/2025, 11:31:00 PM
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

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    set<int> s(all(a));
    vi ava, mis;

    for (int i = 0; i < n; i++){
        if(!s.count(i + 1)) {
            ava.push_back(i + 1);
        }
        
        if(a[i] == 0){
            mis.push_back(i + 1);
        }
    }

    for (int i = 1; i < mis.size(); i++){
        a[mis[i] - 1] = ava[i - 1];
    }

    a[mis[0] - 1] = *ava.rbegin();
    

    for (int i = 0; i < n; i++){
        if(a[i] == i + 1){
            if(a[mis[0] - 1] != a[i])
                swap(a[i], a[mis[0] - 1]);
            else 
                swap(a[i], a[mis[1] - 1]);
        }
    }
    

    cout << a << "\n";
    // cout << ava << "\n" << mis << "\n";
    
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