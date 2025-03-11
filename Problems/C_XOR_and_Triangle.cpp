/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. XOR and Triangle
// URL: https://codeforces.com/contest/2074/problem/C
// Time: 3/11/2025, 4:51:04 PM
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

bool isPow2(int x){
    return x != 0 && (x & (x - 1)) == 0;
}

void Ramez() {
    int x; cin >> x;
    if(isPow2(x) || isPow2(x+1)) {
        cout << "-1\n";
        return;
    } 

    int y = 0;
    y |= 1;  
    
    if ((x & 1) == 0) {
        for (int i = 1; ; i++) {
            if (x & (1 << i)) {
                y |= (1 << i);
                break;
            }
        }
    } else {
        for (int i = 1; ; i++) {
            if ((x & (1 << i)) == 0) {
                y |= (1 << i);
                break;
            }
        }
    }

    cout << y << "\n";
}

/*
NOTES:
10000 = 16 -> -1
01111 = 15 -> -1 

1000100 = 68
0000101 = 5

1000101 = 69
0000011 = 3

110100100 = 420
000000101 = 5
5
101111 = 47
110000 = 48
010001 = 17

1101111011100001000 = 456456
1101111011100000111 = 456455
0000000000000001001 = 9

101111111 = 383
110000000 = 384
010000001 = 129

*/

int32_t main() {


    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}