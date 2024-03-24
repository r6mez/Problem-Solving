#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long numbers[n];

        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        long long smallestSum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                long long sum = numbers[i] + numbers[j] + j - i;
                if(sum < smallestSum) smallestSum = sum;
            }           
        }
        cout << smallestSum;
    }
    return 0;
}