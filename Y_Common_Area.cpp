#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        int left = INT_MIN, top = INT_MIN, right = INT_MAX, bottom = INT_MAX;
        for(int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            left = max(left, x1);
            top = max(top, y1);
            right = min(right, x2);
            bottom = min(bottom, y2);
        }
        int area = (left < right && top < bottom) ? (right - left) * (bottom - top) : 0;
        cout << "Case #" << t << ": " << area << endl;
    }
    return 0;
}