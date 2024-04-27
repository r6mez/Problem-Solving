// ﷽
// problem: I. Bakkar and the Treasure (Hard version)
// URL: https://codeforces.com/group/QI9pPpkbDH/contest/510263/problem/I  
// Start: 4/27/2024, 3:10:01 AM
#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll freq1[200] = {0}, freq2[200] = {0}; 
    for(char c : s) freq2[c]++;

    ll diff = 0, maxDiff = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(freq1[s[i]] == 0 && freq2[s[i]] > 1){
            diff++;
        }
        else if (freq1[s[i]] > 0 && freq2[s[i]] == 1){
            diff--;
        }

        freq1[s[i]]++;
        freq2[s[i]]--;
        maxDiff = max(maxDiff, diff);
    }
    
    cout << maxDiff;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

/*
aabbca
aa bbca

abbbca

abcad
abca d


abccbd
a bccbd

abccad
abcca d


abcdab
*/