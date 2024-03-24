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

    bool isEven = true;
    int numOfOps = 0;

    while (isEven){
        for (int i = 0; i < n; i++)
        {
            if(numbers[i] % 2 == 0){
                numbers[i] = numbers[i] / 2;
            } else {
                isEven = false; 
                break;
            }
        }
        
        if (isEven) numOfOps++;
    }

    cout << numOfOps;
    
    return 0;
}