#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int s = 1;
    for (n; n > 0; n--)
    {
        for (int spaces = n-1; spaces > 0; spaces--)
        {
            cout << " ";
        }

        for (int stars = ((s*2)-1); stars > 0; stars--)
        {
            cout << "*";
        }
        s++;        
        cout << "\n";
    }
    
    return 0;
}