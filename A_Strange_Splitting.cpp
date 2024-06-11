// ﷽
// problem: A. Strange Splitting
// URL: https://codeforces.com/contest/1984/problem/0  
// Start: 6/9/2024, 5:35:19 PM
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
    int n; cin >> n;
    vi a(n);
    map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    if(freq.size() == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        bool printedRed = false;
        for (int i = 0; i < n; i++)
        {
            if(printedRed == false && (freq[a[i]] >= 2 || freq.size() > 2)) {
                cout << "R";
                printedRed = true;
            } else cout << "B";
        }
        cout << "\n";
    }
    
}

/*
NOTES:
You have to color each element of a red or blue so that:
the range of the red elements does not equal the range of the blue elements, 
and there is at least one element of each color.

range = max - min
one should equal 0 (two equal numbers)
and the other all other numbers
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