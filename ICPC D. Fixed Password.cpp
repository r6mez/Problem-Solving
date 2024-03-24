#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    while (true){
        int x;
        cin >> x;
        if(x != 1999) cout << "Wrong\n";
        else {
            cout << "Correct";
            break;
        }
    }
    return 0;
}