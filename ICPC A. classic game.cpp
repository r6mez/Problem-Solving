#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    bool reversed = false;

    int x = 0;
    for (int i = 1; i <= n*n; i++)
    {
        if(!reversed){
            cout << i << " ";
        }
        else{
            cout << i+n-x << " ";
        }

        x = x + 2;
        if(i % n == 0) {
            cout << "\n";
            x = 1;
            reversed = !reversed;
        }
    }
    
    
    return 0;
}