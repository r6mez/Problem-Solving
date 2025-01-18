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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vector<string> mat(n); cin >> mat;

    vi a;
    a.push_back(1);

    for (int i = 1; i < n; i++) {
        bool inserted = false;
        for (int k = 0; k < a.size(); k++) {
            if (mat[i][a[k] - 1] == '1') continue; 

            a.insert(a.begin() + k, i + 1);
            inserted = true;
            break;
        }

        if (!inserted) {
            a.push_back(i + 1);
        }
    }

    cout << a << "\n";
}

/*
NOTES:
  12345
1 00101
2 00101
3 11001
4 00001
5 11110

2 < 1

3 > 1
3 > 2

4 < 1
4 < 2
4 < 3

5 > 1
5 > 2
5 > 3
5 > 4

4 2 1 3 5

NOTES:
  12345
1 00111
2 00111
3 11011
4 11110
5 11100

2 1 3 5 4

2 < 1

3 > 1
3 > 2

4 > 1
4 > 2
4 > 3

5 > 1
5 > 2
5 > 3
5 < 4


*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

