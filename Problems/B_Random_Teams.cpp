/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// B. Random Teams
// URL: https://codeforces.com/contest/478/problem/B
// Time: 3/26/2025, 10:52:33 PM
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
const int MOD = 1000000007;


int pairs(int n){
  return n*(n-1)/2;  
}

void Ramez(){
  int people, teams; cin >> people >> teams;

  int members = people/teams, kemala3adad = people%teams;

  int minCount = (teams - kemala3adad) * pairs(members) + (kemala3adad) * pairs(members + 1);

  int bigTeamMemebers = people - (teams - 1);

  int maxCount = pairs(bigTeamMemebers);

  cout << minCount << " " << maxCount;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}