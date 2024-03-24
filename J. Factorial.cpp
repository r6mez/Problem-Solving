#include <iostream>
using namespace std;

unsigned long long factorial(int n, unsigned long long f = 1){
    if(n == 1) return 1;
    return n * factorial(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << factorial(n);
    return 0;
}
