#include <iostream>
using namespace std;

void printBinary(int n){
    if(n == 0) return;
    printBinary(n/2);
    cout << (n%2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        long long n; cin >> n;
        printBinary(n);
        cout << "\n";
    }
    return 0;
}