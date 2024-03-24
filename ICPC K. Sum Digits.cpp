#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string digits;
    cin >> digits;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int digit = digits[i] - '0';
        sum += digit;
    }

    cout << sum;

    return 0;
}
