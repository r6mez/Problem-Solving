/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// C. Kefa and Company
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/C
// Time: 3/12/2025, 11:40:37 PM
#include <bits/stdc++.h>
#define int long long
using namespace std;

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

int32_t main()
{
    FastIO();
    
    int n, d; cin >> n >> d;
    vector<pair<int, int>> friends(n);
    
    for (int i = 0; i < n; i++)
        cin >> friends[i].first >> friends[i].second;
    
    sort(friends.begin(), friends.end());
    
    int l = 0, r = 0;
    int fs = 0, maxfs = 0;
    
    while (r < n)
    {
        fs += friends[r++].second;
        
        while (friends[r - 1].first - friends[l].first >= d)
        {
            fs -= friends[l++].second;
        }
        
        maxfs = max(maxfs, fs);
    }
    
    cout << maxfs;
}
