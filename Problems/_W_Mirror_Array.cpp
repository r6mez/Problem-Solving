#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    long long numbers[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> numbers[i][k];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < m/2; i++)
        {
            swap(numbers[k][i], numbers[k][m-i-1]);
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cout << numbers[i][k] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}