#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define all(v) v.begin(),v.end()

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n); for (auto& f : s) cin >> f;

    map<int, int> xFreq, yFreq;
    vector<bool> col(m, true), row(n, true);

    for (int i = 0; i < m; i++)
        for (int k = 0; k < n; k++) 
            if (s[k][i] == '.') col[i] = false;
    
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++) 
            if (s[i][k] == '.') row[i] = false;

    bool allFilled = true;

    for (int i = 0; i < n; i++) if(row[i] == false) allFilled = false;
    for (int i = 0; i < m; i++) if(col[i] == false) allFilled = false;
    
    

    int cntMax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isCross = col[j] && row[i];
        
            if (isCross) {
                cntMax++;
                xFreq[i]++;
                yFreq[j]++;
            }
        }
    }

    int cntMin = allFilled? min(xFreq.size(), yFreq.size()) : max(xFreq.size(), yFreq.size());
    cout << cntMax << ' ' << cntMin << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}