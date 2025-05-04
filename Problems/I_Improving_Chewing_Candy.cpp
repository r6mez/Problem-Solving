/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// I. Improving Chewing Candy
// URL: https://codeforces.com/gym/104375/problem/I
// Time: 5/2/2025, 9:45:28 PM
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

int maxSubsetSumDP(const vector<int>& v, int k) {
    vector<bool> dp(k + 1, false);
    dp[0] = true;

    for (int x : v) {
        for (int s = k; s >= x; --s) {
            if (dp[s - x]) dp[s] = true;
        }
    }

    for (int s = k; s >= 0; --s) {
        if (dp[s]) return s;
    }
    return 0;
}

void Ramez() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    vector<pair<char, int>> chunks;
    
    bool loop = s[0] == s[n - 1];
    
    int count = 1;
    for (int i = 0; i < n; i++){
        if(s[i] == s[(i + 1) % n]) {
            count++;
        } else {
            chunks.push_back({s[i], count});
            count = 1;
        } 
    }
    
    if(loop && !chunks.empty()) chunks[0].second += count - 1;
    else chunks.push_back({s[0], count - 1});
    
    // for(auto [c, f] : chunks){
    //     cout << c << " " << f << "\n";
    // } 
    
    map<char, vi> m;
    for(auto [c, f] : chunks){
        m[c].push_back(f);
    }

    string answer = "";
    for(auto [c, v] : m){
        // for each character perform dp on v to get the maximum sum of subsequence that's 
        // less than or equal k and print the letter c as many as the answer is. 
        // cout << v << "\n";
        int sum = maxSubsetSumDP(v, k);
        answer += string(sum, c);
    }

    if((answer.empty()) || (answer.size() == n && loop)) cout << "-1\n";
    else cout << answer.size() << "\n" << answer;
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