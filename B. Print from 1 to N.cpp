#include <iostream>
using namespace std;

void printFrom1toN(int n){
    if (n != 1) printFrom1toN(n-1);
    cout << n << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printFrom1toN(n);
    return 0;
}