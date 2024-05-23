// ﷽
// problem: F - Soltan's Obsession
// URL: https://vjudge.net/contest/630348#problem/F  
// Start: 5/23/2024, 6:04:15 PM
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i;
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

bool isValid(int num, const set<char>& dislikedDigits) {
    string str = to_string(num);
    for (char ch : str) {
        if (dislikedDigits.count(ch) > 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N, K;
    cin >> N >> K;

    set<char> dislikedDigits;
    for (int i = 0; i < K; ++i) {
        char d;
        cin >> d;
        dislikedDigits.insert(d);
    }

    int result = N;
    while (!isValid(result, dislikedDigits)) {
        ++result;
    }

    cout << result << endl;
}

/*
NOTES:

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}