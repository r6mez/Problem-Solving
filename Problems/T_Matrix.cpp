#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    int numbers[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> numbers[i][k];
        }
    }

    int mainSum = 0;
    int primarySum = 0;
    for (int i = 0; i < n; i++)
    {
        mainSum += numbers[i][i];
        primarySum += numbers[n-i-1][i];
    }

    cout << abs(mainSum - primarySum);
    return 0;
}