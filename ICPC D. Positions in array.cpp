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
        if (numbers[i] <= 10) cout << "A[" << i << "]" << " = " << numbers[i] << "\n";
    }
    return 0;
}