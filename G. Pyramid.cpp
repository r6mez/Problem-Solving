#include <iostream>
using namespace std;

void printPyramid(int startStars, int startSpace){
    if(startSpace < 0) return;

    for (int i = startSpace; i > 0; --i) {
        cout << " ";
    }
    for (int i = 0; i < startStars; i++) {
        cout << "*";
    }
    cout << "\n";

    printPyramid(startStars+2, startSpace-1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printPyramid(1, n-1);
    return 0;
}