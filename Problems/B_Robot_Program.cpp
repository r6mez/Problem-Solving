/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Robot Program
// URL: https://codeforces.com/contest/2070/problem/B
// Time: 2/27/2025, 4:53:25 PM
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
    int n, x, k; cin >> n >> x >> k;
    string s; cin >> s;

    int zeros = 0;
    int currTime = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == 'L') x--;
        else x++;
        currTime++;
        if(x == 0){
            zeros++;
            break;
        }
    }

    if(x != 0){
        cout << zeros << "\n"; 
        return;
    }
    

    int length = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == 'L') x--;
        else x++;
        length++;
        if(x == 0){
            zeros++;
            break;
        }

        if(currTime + length >= k) break;
    }


    if(x != 0){
        cout << zeros << "\n"; 
        return;
    }


    k -= currTime + length;
    zeros += k / length;

    cout << zeros << "\n";
}

/*
NOTES:
we need to check first if he will reach zero or not

then we need to check the length of the cycle of movement after the zero to reach zero again
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

