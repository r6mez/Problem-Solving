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

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int max = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    if(numbers[k] > max) max = numbers[k];
                }
                cout << max << " ";    
            }
        }
        cout << "\n";
    }
    return 0;
}