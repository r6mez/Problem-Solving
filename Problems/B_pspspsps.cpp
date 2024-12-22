/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
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
    int n; cin >> n;
    string a; cin >> a;

    int p = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 's') s++;
        else if (a[i] == 'p') p++;
    }

    if(s == 0 || p == 0){
        cout << "YES\n"; 
        return;
    }
    

    if((a[0] == 's' && s == 1) || (a[n-1] == 'p' && p == 1)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

/*
NOTES:
if s0 = s and sn-1 = p
ppppssss not okay
12345678

sssspppp not okay
12345789

s...pppp okay
12345789

ssss...p okay 
12345789

it must has only one s at start and then b's
or only s's and one b at end 


only has p's
p...p.p.. okay
...p..p.. okay
1 2 3 4 

only has  s's
..s.ss.s.
4 3 2 1


..sp.. no
..ps.. no
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

