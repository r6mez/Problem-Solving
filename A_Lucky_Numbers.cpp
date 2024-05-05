// ﷽
// problem: A. Lucky Numbers
// URL: https://codeforces.com/problemset/problem/1808/A  
// Start: 5/5/2024, 7:03:15 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>


int getDiff(int num) {
    int maxDigit = INT_MIN;
    int minDigit = INT_MAX;
    while (num != 0) {
        maxDigit = max(maxDigit, num % 10);
        minDigit = min(minDigit, num % 10);
        num /= 10;
    }
    return maxDigit - minDigit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int maxDiff = -1, iMaxDiff = l;
        for (int i = l; i <= r; i++)
        {
            int diff = getDiff(i);
            if (diff == 9) { iMaxDiff = i; break; }
            if(maxDiff <= diff){
                maxDiff = diff;
                iMaxDiff = i;
            }
        }
        cout << iMaxDiff << "\n";
    }
    return 0;
}
