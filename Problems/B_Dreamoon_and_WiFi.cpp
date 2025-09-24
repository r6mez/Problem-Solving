/*
    One day, I'm gonna grow wings
*/
// B. Dreamoon and WiFi
// URL: https://codeforces.com/problemset/problem/476/B
// Time: 9/24/2025, 7:12:01 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

string original, received;

int total = 0, successful = 0;
int expextedScore = 0;

void calc(int i, int currSocre) {
    if(i == original.size()){
        if (currSocre == expextedScore) successful++;
        total++;
        return;
    }

    if(received[i] == '+') calc(i + 1, currSocre + 1);
    else if(received[i] == '-') calc(i + 1, currSocre - 1);
    else {
        calc(i + 1, currSocre + 1);
        calc(i + 1, currSocre - 1);
    }
}


void solve() {
    cin >> original >> received;

    for (int i = 0; i < original.size(); i++){
        if(original[i] == '+') expextedScore++;
        else expextedScore--;
    }

    calc(0, 0);

    double answer = (double)successful / total;
    cout << fixed << setprecision(12) << answer << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}