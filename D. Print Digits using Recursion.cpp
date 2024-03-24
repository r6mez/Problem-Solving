#include <iostream>
using namespace std;

void printDigits(long long n){
    if(n < 10) {
        cout << n << " ";
        return;
    }
    printDigits(n/10);
    cout << n%10 << " ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        long long n; cin >> n;
        printDigits(n);
        cout << "\n";
    }
    return 0;
}