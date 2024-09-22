#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    string x, y;
    cin >> x >> y;
    int lastDigitX = int(x[x.length() - 1] - '0');
    int lastDigitY = int(y[y.length() - 1] - '0');
    int sum = lastDigitX + lastDigitY;
    if (sum % 2 == 0) {
        cout << "Even.";
    } else {
        cout << "Odd.";
    }

    return 0;
}
