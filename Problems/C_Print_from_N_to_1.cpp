#include <iostream>
using namespace std;

void printFromNto1(int n){
    if (n != 1){
        cout << n << " ";
        printFromNto1(n-1);
    } else {
        cout << 1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printFromNto1(n);
    return 0;
}