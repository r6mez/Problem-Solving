#include <iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << sum(a,b);
    return 0;
}