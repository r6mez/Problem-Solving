/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Remove the Ends
// URL: https://codeforces.com/contest/2064/problem/C
// Time: 2/16/2025, 5:37:25 PM
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
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int allPos = 0, allNeg = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > 0) allPos += a[i];
        else allNeg -= a[i];
    }

    vi posArr(a), negArr(a);
    for (int i = 0; i < n; i++){
        if(posArr[i] < 0) posArr[i] = 0;
        if(negArr[i] > 0) negArr[i] = 0;
        else negArr[i] *= -1;
    }

    partial_sum(all(posArr), posArr.begin());
    partial_sum(negArr.rbegin(), negArr.rend(), negArr.rbegin());

    int bruteScore = 0;
    for (int i = 0; i < n-1; i++){
        bruteScore = max(bruteScore, posArr[i] + negArr[i+1]);
    }


    cout << max({allPos, allNeg, bruteScore}) << "\n";
}

/*
NOTES:
negative -> delete suffix (start from end)
positive -> delete prefix  (start from start)
gain |a[i]| coins

left can't get over right 
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

