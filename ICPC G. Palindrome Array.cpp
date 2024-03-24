#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int isPil = true;
    for (int i = 0; i < n/2; i++)
    {   
        if(numbers[i] != numbers[n-i-1]) isPil = false;
    }
    
    if(isPil) cout << "YES";
    else cout << "NO";
    return 0;
}