#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int left = 0, right = 0;
        while (left < n && s[left] == '<')
        {
            left++;
        }
        while (right < n && s[n - 1 - right] == '>')
        {
            right++;
        }
        cout << min(left,right) << "\n";
    }
    return 0;
}