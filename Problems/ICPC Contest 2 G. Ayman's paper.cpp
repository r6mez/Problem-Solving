#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;
    int min = 0;
    
    if (a > b) min = b;
    else min = a;

    for (int i = min; i > 0; i--)
    {
        if(a % i == 0 && b % i == 0){
            cout << i;
            break;
        }
    }
    

    return 0;
}