/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Hate "A"
// URL: https://codeforces.com/contest/1146/problem/B
// Time: 3/22/2025, 12:39:31 PM
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
    string t; cin >> t;
    int n = t.size();

    int cntNonA = 0;
    for (int i = 0; i < n; i++){
        if(t[i] != 'a') cntNonA++;
    }
    
    if(cntNonA == 0){
        cout << t;
        return;
    }
    
    if(cntNonA % 2 == 1){
        cout << ":(";
        return;
    }

    int half = cntNonA / 2;
    int indexOfElementAfterHalf = 0, counter = 0;
    for (int i = 0; i < n; i++){
        if(t[i] != 'a') counter++;
        indexOfElementAfterHalf++;
        if(counter == half + 1) break;
    }

    for (int i = indexOfElementAfterHalf; i < n; i++){
        if(t[i] == 'a') {
            cout << ":(";
            return;
        }
    }
    
    string s = "";
    for (int i = 0; i < n; i++){
        if(t[i] != 'a') s.push_back(t[i]);
    }
    
    if(s.substr(0, half) == s.substr(half, n)){
        cout << t.substr(0, indexOfElementAfterHalf - 1);
    } else {
        cout << ":(";
    }
}

/*
NOTES:
ababacacaaabbcc
bbccbbcc 

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}