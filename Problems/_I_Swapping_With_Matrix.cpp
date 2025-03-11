#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,x,y;
    cin >> n >> x >> y;

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        swap(matrix[x-1][i], matrix[y-1][i]);
    }    

    for (int i = 0; i < n; i++)
    {
        swap(matrix[i][x-1], matrix[i][y-1]);
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}