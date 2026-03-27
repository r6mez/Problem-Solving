#include "bits/stdc++.h"
#include <cstdio>
using namespace std;

int main () {
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int curr_pos = 50;
    int password = 0;

    char dir;
    int move;
    while (cin >> dir >> move) {
        if (dir == 'R') {
            password += (curr_pos + move) / 100;
        } else {
            if (curr_pos == 0) password += move / 100;
            else if (move >= curr_pos) password += 1 + (move - curr_pos) / 100;
        }

        if(dir == 'L') move = -move;
        curr_pos = ((curr_pos + move) % 100 + 100) % 100;
    }

    cout << password << endl;
    return 0;
}