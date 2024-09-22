#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    char cells[n][n];
    int G, E, S, H; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cells[i][j];
            switch(cells[i][j]){
                case 'G': G = i; break;
                case 'E': E = i; break;
                case 'S': S = i; break;
                case 'H': H = i; break;
            }
        }
    }

    if((G != S) && (G != H) && (G != E) && !(S > G && G > E) && !(S < G && G < E) && !(H > G && G > E) && !(H < G && G < E)) 
        cout << "Scooby-Dooby-Doo!";
    else 
        cout << "Ruh-roh--RAGGY!!!";
    
    return 0;
}