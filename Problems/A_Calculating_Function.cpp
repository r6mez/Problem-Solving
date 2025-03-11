#include <iostream> 
#include <math.h>
using namespace std;

void calcFunction(){
    int n;
    cin >> n;

    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        result += ((pow(-1,i))*i);
    }
    
    cout << result;
}


int main(){
    calcFunction();
    return 0;
}