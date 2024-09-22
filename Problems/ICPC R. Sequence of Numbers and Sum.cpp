#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    while (n > 0 && m > 0){
        int biggerNumber;
        int smallerNumber;
        if(n > m){
            biggerNumber = n;
            smallerNumber = m;  
        } 
        else {
            biggerNumber = m;
            smallerNumber = n;
        }

        int sum = 0;
        for (int i = smallerNumber; i <= biggerNumber; i++)
        {
            cout << i << " ";
            sum += i;
        }
        cout << "sum ="<< sum << "\n";
        cin >> n >> m;
    }
    return 0;
}