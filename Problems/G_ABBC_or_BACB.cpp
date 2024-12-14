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
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    string s; cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == 'A'){
            a++;
        } else {
            b++;
        }
    }

    if(!b) {
        cout << 0 << "\n";
        return;
    }

    if(s[0] == 'B' || s[n-1] == 'B') {
        cout << a << "\n";
        return;
    } else {
        int minGroup = INT_MAX, currGroup = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == 'A') {
                currGroup++;
            } else {
                minGroup = min(minGroup, currGroup);
                currGroup = 0;
            }
            if(minGroup == 0) break;
        }

        if(s[n-1] == 'A') minGroup = min(minGroup, currGroup);

        int answer = a - minGroup;
        cout << answer << "\n";
    }
}

/*
NOTES:
AB -> BC
BA -> CB

AAAAB -> AAABC -> AABCC -> ABCCC -> BCCCC
BAAAA -> CBAAA -> CCBAA -> CCCBA -> CCCCB
AAB -> ABC -> BCC
BAA -> CBA -> CCB

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

