#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl '\n'
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), even, odd;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] & 1) 
                odd.pb(v[i]);
            else 
                even.pb(v[i]);
        }
        
        // All even
        if (odd.empty()) {
            for (int i = 0; i < n; i++) 
                cout << 0 << ' ';
            cout << endl;
            continue;
        }
        
        // All odd
        if (even.empty()) {
            sort(all(odd), greater<int>());
            for (int k = 1; k <= n; k++) {
                if (k & 1) {
                    int sum = 0;
                    for (int i = 0; i < k; i++) 
                        sum += odd[i];
                    cout << sum << ' ';
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << endl;
            continue;
        }
        
        // Mixed case
        sort(all(odd), greater<int>());
        sort(all(even), greater<int>());
        
        int maxOdd = odd[0];
        
        for (int k = 1; k <= n; k++) {
            int ans = 0;
            
            // Use only odd coins (if k is odd and possible)
            if ((k & 1) && k <= odd.size()) {
                int sum = 0;
                for (int i = 0; i < k; i++) 
                    sum += odd[i];
                ans = max(ans, sum);
            }
            
            // Use 1 odd + evens  
            if (k <= even.size() + 1) {
                int sum = maxOdd;
                for (int i = 0; i < min((int)even.size(), k - 1); i++) 
                    sum += even[i];
                ans = max(ans, sum);
            }
            
            // When we need more than all evens + 1 odd
            if (k > even.size() + 1) {
                int numOdds = k - even.size();
                
                if (numOdds & 1) {
                    // Odd number of odds can keep max_odd + all evens
                    int sum = maxOdd;
                    for (int i = 0; i < even.size(); i++) 
                        sum += even[i];
                    ans = max(ans, sum);
                } else {
                    // Even number of odds needed
                    // Try using one more odd and one fewer even
                    if (even.size() >= 1 && numOdds + 1 <= odd.size()) {
                        int sum = maxOdd;
                        for (int i = 0; i < even.size() - 1; i++) 
                            sum += even[i];
                        ans = max(ans, sum);
                    }
                    // Otherwise answer is 0
                }
            }
            
            cout << ans << ' ';
        }
        cout << endl;
    }
}

signed main() {
    fast;
    solve();
    return 0;
}