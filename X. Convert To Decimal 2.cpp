#include <iostream>
#include <math.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--){
        int decimal;
        cin >> decimal;
        string binary = "";
        while (decimal){
            binary = to_string(decimal%2) + binary;
            decimal = decimal / 2;
        }
        
        string newBinary = "";
        for (char c : binary)
        {
            if(c == '1'){
              newBinary = '1' + newBinary;
            }
        }
        
        int newDecimal = 0;
        for (int i = (newBinary.length() - 1); i >= 0; i--)
        {
            int bit = int(newBinary[i] - '0');
            newDecimal += (bit * pow(2,i));
        }
        
        cout << newDecimal << "\n";
    }

    return 0;
}