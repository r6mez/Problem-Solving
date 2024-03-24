#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int a,b;
    cin >> a >> b;
    int numberOfPlots;

    while(a && b){
        if (a > b) {
            numberOfPlots += a / b;
            a = a % b;
        }
        else {
            numberOfPlots += b / a;
            b = b % a;
        }
    }

    cout << numberOfPlots; 
    return 0;
}