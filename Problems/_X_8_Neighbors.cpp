#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    char numbers[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> numbers[i][k];
        }
    }

    int x,y;
    cin >> x >> y;

    bool isNeighbors = true;
    
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0) continue;
            if(numbers[x+i-1][y+j-1] == '.') isNeighbors = false;
        }
    }

    if (isNeighbors) cout << "yes";
    else cout << "no";
    return 0;
}