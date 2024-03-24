#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
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
        for (int i = smallerNumber+1; i < biggerNumber; i++)
        {
            if (i % 2 != 0){
                sum += i;
            } 
        }
        cout << sum << "\n";
    }
    return 0;
}