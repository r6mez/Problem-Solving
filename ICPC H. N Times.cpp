#include <iostream>

using namespace std;

void printCharNTimes(char c, int n){
    while(n--){
        cout << c;
        if (n != 0) cout << " ";
    }
    cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        char c;
        int n;
        cin >> n >> c;
        printCharNTimes(c,n);
    }
    
    return 0;
}