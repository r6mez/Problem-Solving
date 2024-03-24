#include <iostream>
#include <vector>
using namespace std;

void printEvenIndicesReverse(int arr[], int index) {
    if (index < 0) {
        return;
    }
    if (index % 2 == 0) {
        cout << arr[index] << " ";
    }
    printEvenIndicesReverse(arr, index - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    printEvenIndicesReverse(a,n-1);
    return 0;
}