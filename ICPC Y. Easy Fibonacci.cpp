#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> febonacci = {0,1};

    for (int i = 2; i <= 45; i++)
    {
        febonacci.push_back(febonacci[i-1] + febonacci[i-2]);
    }
    
    for (int m = 0; m < n; m++)
    {
        cout << febonacci[m] << " ";
    }
    
    return 0;
}