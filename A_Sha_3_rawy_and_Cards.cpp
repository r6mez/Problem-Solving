// ﷽
// problem: A - Sha3rawy and Cards
// URL: https://vjudge.net/contest/632920#problem/A  
// Start: 6/7/2024, 5:31:37 PM
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

#include <unordered_map>

unordered_map<string, ll> m;

ll countWays(vi& x, int n, int a, int i, int sum, int count) {
    if (i == n) {
        return (count > 0 && sum == count * a) ? 1 : 0;
    }

    string key = to_string(i) + " " + to_string(sum) + " " + to_string(count);
    if (m.find(key) != m.end()) {
        return m[key];
    }

    ll ways = 0;
    ways += countWays(x, n, a, i + 1, sum, count);
    ways += countWays(x, n, a, i + 1, sum + x[i], count + 1);
    m[key] = ways;
    return ways;
}

int main() {
    int n, a;
    cin >> n >> a;  
    vi x(n); cin >> x;

    ll ways = countWays(x, n, a, 0, 0, 0);
    cout << ways << endl;

    return 0;
}