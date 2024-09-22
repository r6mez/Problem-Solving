#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int current = 1;  // The current positive integer
    int i = 0;        // Index for the input array
    int missingCount = 0;

    while (missingCount < k) {
        if (i < n && numbers[i] == current) {
            i++;
        } else {
            missingCount++;
        }

        if (missingCount == k) {
            cout << current << "\n";
            break;
        }

        current++;
    }

    return 0;
}
