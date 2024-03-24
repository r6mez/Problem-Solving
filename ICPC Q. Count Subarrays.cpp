#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int t; 
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int numbers[n];

        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        int numOfNonDecreasing = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool nonDecreasing = true;
                for (int k = i; k < j; k++)
                {
                    if(!(numbers[k] <= numbers[k+1])) nonDecreasing = false;
                }
                if (nonDecreasing) numOfNonDecreasing++;    
            }
        }

        cout << numOfNonDecreasing << "\n";
    }
    return 0;
}