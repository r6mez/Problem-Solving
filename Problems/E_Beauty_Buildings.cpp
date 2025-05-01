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
    string s; cin >> s;
    int maxSub = -1, currSub = 0;
    char lastChar = s[0];
    for (int i = 0; i < n; i++){
        if(s[i] == lastChar) currSub++;
        else maxSub = max(maxSub, currSub), currSub = 1;
        lastChar = s[i];
    }
    maxSub = max(maxSub, currSub);

    int beginSize = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == s[0]) beginSize++;
        else break;
    }
    
    int currDup = 0, maxDup = -1;
    for (int i = beginSize; i < n; i++){
        if(s[i] == s[0]) currDup++;
        else maxDup = max(maxDup, currDup), currDup = 0;
    }
    maxDup = max(maxDup, currDup);

    int answer = max(maxSub, beginSize + maxDup);
    cout << answer << "\n";
}
 
/*
NOTES:
it's either 
    The first characters + longest substring of it late
or  longest substring of any character later
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

