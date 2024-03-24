#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    unsigned long long n,a,b;
    cin >> n >> a >> b;
    unsigned long long num = n/(a+b);
    cout << num;
    return 0;
}