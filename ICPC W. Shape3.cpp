#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int s = 1;
    for (int i = n; i > 0; i--)
    {
        for (int spaces = i-1; spaces > 0; spaces--)
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

    s = 0;
    for (int i = n; i > 0; i--)
    {
        for (int spaces = 0; spaces < s; spaces++)
        {
            cout << " ";
        }
        s++;

        for (int stars = n*2 - 2; stars >= 0; stars--)
        {
            cout << "*";
        }
        n--;        
        cout << "\n";
    }
    return 0;
}