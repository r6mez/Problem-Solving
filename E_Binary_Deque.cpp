// ﷽
// problem: E. Binary Deque
// URL: https://codeforces.com/problemset/problem/1692/E  
// Start: 6/5/2024, 6:43:34 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum < s) {
        cout << -1 << endl;
        return;
    }
    
    if (sum == s) {
        cout << 0 << endl;
        return;
    }
    
    int currentSum = 0;
    int minLength = n + 1;
    int start = 0;
    
    for (int end = 0; end < n; ++end) {
        currentSum += a[end];
        
        while (currentSum > s) {
            currentSum -= a[start];
            start++;
        }
        
        if (currentSum == s) {
            minLength = min(minLength, n - (end - start + 1));
        }
    }
    
    cout << minLength << endl;
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}