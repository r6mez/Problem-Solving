/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// D - Maximum Product
// URL: https://vjudge.net/contest/696623#problem/D
// Time: 3/1/2025, 12:54:34 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

// Structure for DP state result: best product and the number (as a string)
struct Result {
    int prod;
    string num;
};

// Global DP array for states dp[pos][lTight][hTight]
Result dp[22][2][2];
// Global variables for the fixed-length lower/upper bounds and current length L.
string lowStr, highStr;
int L;

// f(pos, lt, ht):
//  pos: current digit position [0,L)
//  lt: still tight with the lower bound (lowStr)
//  ht: still tight with the upper bound (highStr)
// Returns the best (max product, number string) for positions pos..L-1.
Result f(int pos, int lt, int ht) {
    if (pos == L) return { 1, "" };  // multiplicative identity at end
    if (dp[pos][lt][ht].prod != -1) return dp[pos][lt][ht];
    Result best = { -1, "" };
    int loDigit = (lt ? lowStr[pos] - '0' : 0);
    int hiDigit = (ht ? highStr[pos] - '0' : 9);
    if (pos == 0) loDigit = max(loDigit, 1LL);  // first digit must be at least 1
    for (int d = loDigit; d <= hiDigit; d++) {
        int nlt = lt && (d == (lowStr[pos] - '0'));
        int nht = ht && (d == (highStr[pos] - '0'));
        Result child = f(pos + 1, nlt, nht);
        int prodCandidate = d * child.prod;
        if (prodCandidate > best.prod) {
            best.prod = prodCandidate;
            best.num = char('0' + d) + child.num;
        }
    }
    return dp[pos][lt][ht] = best;
}

// Returns the smallest L-digit number as a string, e.g. L=4 -> "1000"
string makeLower(int L) {
    string s = "1";
    s.append(L - 1, '0');
    return s;
}

// Returns the largest L-digit number as a string, e.g. L=4 -> "9999"
string makeUpper(int L) {
    return string(L, '9');
}

void Ramez() {
    string sA, sB;
    cin >> sA >> sB;
    int lenA = sA.size(), lenB = sB.size();
    Result bestOverall = { -1, "" };
    // Try each fixed length from the length of a to the length of b.
    for (int Lcurr = lenA; Lcurr <= lenB; Lcurr++) {
        string currLow = (Lcurr == lenA ? sA : makeLower(Lcurr));
        string currHigh = (Lcurr == lenB ? sB : makeUpper(Lcurr));
        lowStr = currLow; highStr = currHigh; L = Lcurr;
        // Reset the DP table for the current length.
        for (int i = 0; i <= L; i++)
            for (int lt = 0; lt < 2; lt++)
                for (int ht = 0; ht < 2; ht++)
                    dp[i][lt][ht] = { -1, "" };
        Result candidate = f(0, 1, 1);
        if (candidate.prod > bestOverall.prod)
            bestOverall = candidate;
    }
    cout << bestOverall.num << "\n";
}

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}
