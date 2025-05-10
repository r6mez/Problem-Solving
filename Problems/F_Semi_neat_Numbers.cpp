/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// F. Semi-neat Numbers
// URL: https://codeforces.com/group/Rilx5irOux/contest/605910/problem/F
// Time: 5/9/2025, 5:32:10 PM
#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("neat.in", "r", stdin); }
const int MOD = 1000000007;

void Ramez() {
    string a; cin >> a;
    int x; cin >> x;
    int n = a.size();

    vector<string> ans;
    string curr = "";
    curr += a[0];

    for (int i = 1; i < n; i++){
        if(a[i] == '0'){
            if(!curr.empty()) ans.push_back(curr);
            curr = "0";
            ans.push_back(curr);
            curr = "";
            continue;
        }

        if(i <= n - (x - ans.size())){
            if(a[i] >= a[i - 1]){
                curr += a[i];
                continue;
            } 
            
            if(!curr.empty()) ans.push_back(curr);
            curr = a[i];
            // ans.push_back(curr);
            // curr = "";
        } else {
            if(!curr.empty()) ans.push_back(curr);
            curr = a[i];
            ans.push_back(curr);
            curr = "";
        }
    }
    
    if(!curr.empty()) ans.push_back(curr);
    
    // cout << ans.size() << "\n";
    // cout << ans << "\n";
    if(ans.size() != x){
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

/*
NOTES:
zero must be last choosen alone 
*/

int32_t main() {
    UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}