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
    string s, t; cin >> s >> t;

    int as = 0, bs = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') as++;
        else bs++;

        if (t[i] == 'a') as++;
        else bs++;
    }

    if (as % 2 || bs % 2) {
        cout << -1 << "\n";
        return;
    }

    vector<pair<int, int>> ops;

    queue<int> ba, ab;


    for (int i = 0; i < n; i++) {
        // a
        // b
        if (s[i] == 'a' && t[i] == 'b') {
            if (!ab.empty()) {
                int j = ab.front();
                ab.pop();
                swap(s[i], t[j]);
                ops.push_back({ i + 1, j + 1 });
            }
            else {
                ab.push(i);
            }
        }

        // b
        // a
        if (s[i] == 'b' && t[i] == 'a') {
            if (!ba.empty()) {
                int j = ba.front();
                ba.pop();
                swap(s[i], t[j]);
                ops.push_back({ i + 1, j + 1 });
            }
            else {
                ba.push(i);
            }
        }
    }

    if (!ba.empty() && !ab.empty()) {
        int i = ab.front(), j = ba.front();
        ab.pop(); ba.pop();

        swap(s[i], t[i]);
        swap(s[i], t[j]);

        ops.push_back({ i + 1, i + 1 });
        ops.push_back({ i + 1, j + 1 });
    }

    // cout << s << "\n" << t << "\n";

    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i].first << " " << ops[i].second << "\n";
    }

}

/*
NOTES:
babbaabb
abababaa

aa
bb

bb
aa

i j


ab
ba

i i
i j
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

