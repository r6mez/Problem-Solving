    // ﷽
    // problem: D. GCD-sequence
    // URL: https://codeforces.com/contest/1980/problem/D  
    // Start: 6/3/2024, 7:01:46 PM
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
    #include <numeric>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define vi vector<int>
    #define vll vector<long long>
    #define all(v)  v.begin(), v.end()

    template<typename T>
    ostream& operator<<(ostream& os, const vector<T>& v) {
        for (const auto& i : v) os << i << ' ';
        return os;
    }

    template<typename T>
    istream& operator>>(istream& is, vector<T>& v) {
        for (auto& i : v) is >> i;
        return is;
    }

    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> gcdArray;
        for (int i = 0; i < n - 1; i++) {
            gcdArray.push_back(gcd(nums[i], nums[i + 1]));
        }

        int index = -1;
        for (int i = 0; i < n - 2; i++) {
            if (gcdArray[i] > gcdArray[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "YES" << endl;
            return;
        }

        vector<int> modifiedNums1, modifiedNums2, modifiedNums3;
        for (int i = 0; i < n; i++) {
            if (i != index + 1) {
                modifiedNums1.push_back(nums[i]);
            }
            if (i != index + 2) {
                modifiedNums2.push_back(nums[i]);
            }
            if (i != index) {
                modifiedNums3.push_back(nums[i]);
            }
        }

        vector<int> modifiedGCD1, modifiedGCD2, modifiedGCD3;
        for (int i = 0; i < n - 2; i++) {
            modifiedGCD1.push_back(gcd(modifiedNums1[i], modifiedNums1[i + 1]));
            modifiedGCD2.push_back(gcd(modifiedNums2[i], modifiedNums2[i + 1]));
            modifiedGCD3.push_back(gcd(modifiedNums3[i], modifiedNums3[i + 1]));
        }

        bool flag1 = true, flag2 = true, flag3 = true;
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGCD1[i] > modifiedGCD1[i + 1]) {
                flag1 = false;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGCD2[i] > modifiedGCD2[i + 1]) {
                flag2 = false;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGCD3[i] > modifiedGCD3[i + 1]) {
                flag3 = false;
                break;
            }
        }

        if (!(flag1 || flag2 || flag3)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    /*
    NOTES:

    */

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        return 0;
    }