#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    char s;
    int n;
    cin >> s >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cout << s; 
        }
        cout << "\n";
    }
    
    return 0;
}