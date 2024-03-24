#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    
    int m,n,k;
    cin >> m >> n >> k;
    char signal[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> signal[i][j];
        }
    }

    char amplifiedSignal[m*k][n*k];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int a = 0; a < k; a++)
            {
                for (int b = 0; b < k; b++)
                {
                   amplifiedSignal[(i*k)+a][(j*k)+b] = signal[i][j]; 
                }      
            }
        }
    }

    for (int i = 0; i < m*k; i++)
    {
        for (int j = 0; j < n*k; j++)
        {
            cout << amplifiedSignal[i][j];
        }
        cout << endl;
    }
    

    return 0;
}