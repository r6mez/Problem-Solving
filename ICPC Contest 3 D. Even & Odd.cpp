#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<long long> even, odd;
    for (int i = 0; i < n; i++) {
        if (num[i] % 2 == 0) {
            even.push_back(num[i]);
        } else {
            odd.push_back(num[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << even[evenIndex] << " ";
            evenIndex++;
        } else {
            cout << odd[oddIndex] << " ";
            oddIndex++;
        }
    }

    return 0;
}
