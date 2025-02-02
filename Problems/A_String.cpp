/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// A. String
// URL: https://codeforces.com/contest/2062/problem/A
// Time: 1/26/2025, 4:35:21 PM
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;
const int  dx[]  = { -1,   1,   0,   0  };
const int  dy[]  = {  0,   0,  -1,   1  };
const char dir[] = { 'U', 'D', 'L', 'R' };


void Ramez() {
    string s; cin >> s;
    ll c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') c++;
    }
    cout << c << "\n";
}

/*
NOTES:
1001
0100
0000

10101
01010
00100
00000

01100101011101


101 = 010

1010 = 0101 no dif

10101

11111
11011
10101
01010
00100
00000
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

