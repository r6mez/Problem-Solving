#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n,a,b;
    cin >> n >> a >> b;
    int sumOfNumbers = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int n1 = i/1000 , n2 = i/100 -  (n1 * 10), n3 = (i/10) - (n1 * 100 + n2 * 10), n4 = (i) - (n1 * 1000 + n2 * 100 + n3 * 10);
        if(n1+n2+n3+n4 >= a && n1+n2+n3+n4 <= b) sumOfNumbers += i;
    }
    
    cout << sumOfNumbers;
    return 0;
}   