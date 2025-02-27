/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. permutations
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/263096/problem/C
// Time: 2/26/2025, 2:11:55 PM
#include <bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#include <vector>

int main() {
    FAST
        int n, q; cin >> n >> q;
    string s; cin >> s;

    while (q--) {
        string t; cin >> t;

        if (t == "next_permutation") {
            int x; cin >> x;
            while (x--) next_permutation(s.begin(), s.end());
            cout << s << endl;
        }
        else if (t == "prev_permutation") {
            int x; cin >> x;
            while (x--) prev_permutation(s.begin(), s.end());
            cout << s << endl;
        }
    }

    return 0;
}

