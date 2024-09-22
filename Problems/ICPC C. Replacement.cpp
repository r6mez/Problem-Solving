#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(numbers[i] > 0) cout << 1 << " ";
        else if (numbers[i] < 0) cout << 2 << " ";
        else cout << 0 << " ";  
    }
    return 0;
}