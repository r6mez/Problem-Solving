#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
       
    int n;
    cin >> n; 
    for (int j = 2; j <= n; j++)
    {
        bool isPrime = true;
        for (int i = 2; i < j; i++)
        {   
            if (j%i==0) isPrime = false;
        }
        if(isPrime) cout << j << " ";
    }
    
    
    return 0;
}