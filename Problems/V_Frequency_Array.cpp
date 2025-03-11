#include <iostream>
#include <vector>
using namespace std;



int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int numbers[n];
    vector<int> freq(m + 1, 0); 
    

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        freq[numbers[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        cout << freq[numbers[i]] << "\n";
    }
    
    return 0;
}