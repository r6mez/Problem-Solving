#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to calculate MEX of a subgrid
int calculateMEX(const vector<int>& elements) {
    set<int> s(elements.begin(), elements.end());
    int mex = 0;
    while (s.count(mex)) ++mex;
    return mex;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    long long totalMEXSum = 0;

    // Iterate over all subgrids
    for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x2 = x1; x2 < n; ++x2) {
                for (int y2 = y1; y2 < n; ++y2) {
                    vector<int> elements;

                    // Collect elements in the current subgrid
                    for (int i = x1; i <= x2; ++i)
                        for (int j = y1; j <= y2; ++j)
                            elements.push_back(grid[i][j]);

                    int mex = calculateMEX(elements);
                    // cout << mex << " ";
                    totalMEXSum += mex;
                }
            }
        }
    }

    // cout << "\n";
    cout << totalMEXSum << endl;
    return 0;
}
