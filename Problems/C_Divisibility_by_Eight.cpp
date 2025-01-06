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
    string s; cin >> s;
    int n = s.size();

    // one num
    for (int i = 0; i < n; i++) {
        if (s[i] == '8' || s[i] == '0') {
            cout << "YES\n";
            cout << s[i];
            return;
        }
    }

    //two nums
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if (num % 8 == 0) {
                cout << "YES\n" << num;
                return;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (num % 8 == 0) {
                    cout << "YES\n" << num;
                    return;
                }
            }
        }
    }
    
    cout << "NO\n";
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

