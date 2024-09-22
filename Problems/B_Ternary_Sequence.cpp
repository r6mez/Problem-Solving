// ﷽
// problem: B. Ternary Sequence
// URL: https://codeforces.com/problemset/problem/1401/B  
// Start: 6/4/2024, 10:04:13 PM
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
    int a0, a1, a2; 
    int b0, b1, b2;
    cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
    
    int sum = 0;
    int m;
    m = min(a0, b2);
	a0 -= m;
	b2 -= m;

	m = min(a1, b0);
	a1 -= m;
	b0 -= m;

	m = min(a2, b1);
	a2 -= m;
	b1 -= m;
	sum += 2 * m;

	sum -= 2 * min(a1, b2);

	cout << sum << "\n";
}

/*
NOTES:
a b 
2 1 +2 
1 2 -2

a2 > b1
sum += (b1)*2;
a2 < b1 
sum += (a2)*2

(b1-a0-a1) > 0


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