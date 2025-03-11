#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int spaces = n-1;
    int element = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = spaces; j > 0; j--)
        {
            cout << ' ';
        }
        spaces--;
        
        for (int j = 0; j < element; j++)
        {   
            int character = 65+(j%26);
            cout << char(character);
        }
        element += 2;

        cout << "\n";
    }
    
    return 0;
}