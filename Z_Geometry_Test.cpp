#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    double R, S;
    cin >> R >> S;
    double circleDiameter = 2 * R;
    double squareDiagonal = S * sqrt(2);

    if (circleDiameter >= squareDiagonal) {
        cout << "Circle" << endl;
    } else if (circleDiameter <= S) {
        cout << "Square" << endl;
    } else {
        cout << "Complex" << endl;
    }
    return 0;
}
