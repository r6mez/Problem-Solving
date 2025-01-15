/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
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

void Ramez() {

}

/*
NOTES:
currMex;
freq[i] i = 0 .. max(a);
M = min(freq[i] * currMex + (n - freq[i]) * i)
there's a problem ... 
sometimes reducing the curMex first would result 
in a smaller M 

from what we know reducing happens by 
choosing another small element probably 1 first
then choosing 0 

0 1 2 0 1 2 0 3
0 0 0 1 1 2 2 3
4 + 1 + 1 + 1 + 0 + 0 + 0 + 0

0 0 0 1 1 1 2 2 3
4 + 4 + 1 + 1 + 1 =  11

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

