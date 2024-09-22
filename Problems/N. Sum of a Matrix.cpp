#include <iostream>
#include <vector>

using namespace std;

void printSumOfTwoMatrix(const vector<vector<int>>& a, const vector<vector<int>>& b, int r, int c, int i = 0, int j = 0) {
    if (i >= r) return;
    if (j >= c) {
        i++;
        j = 0;
        cout << "\n";
    }
    if (i < r && j < c) {
        cout << (a[i][j] + b[i][j]) << " ";
        printSumOfTwoMatrix(a, b, r, c, i, ++j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;

    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> b[i][j];
        }
    }

    printSumOfTwoMatrix(a, b, r, c);
    return 0;
}