#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    string m , a, r;
    cin >> m >> a >> r;


    char turn = 'm';
    int mI = 0, aI = 0, rI = 0;
    int mLast = m.length() - 1;
    int aLast = a.length() - 1;
    int rLast = r.length() - 1;

    while (true) {
        switch (turn) {
            case 'm':
                if (mI <= mLast) {
                    turn = m[mI];
                    mI++;
                } else {
                    cout << "M";
                    return 0;
                }
                break;
            case 'a':
                if (aI <= aLast) {
                    turn = a[aI];
                    aI++;
                } else {
                    cout << "A";
                    return 0;
                }
                break;
            case 'r':
                if (rI <= rLast) {
                    turn = r[rI];
                    rI++;
                } else {
                    cout << "R";
                    return 0;
                }
                break;
        }
    }

    return 0;
}
