#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int numbers[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> numbers[i][k];
        }
    }

    int num;
    cin >> num;

    bool numberExist = false;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (numbers[i][k] == num){
                numberExist = true;
            }
        }
    }

    if(numberExist) cout << "will not take number";
    else cout << "will take number";
    
    return 0;
}