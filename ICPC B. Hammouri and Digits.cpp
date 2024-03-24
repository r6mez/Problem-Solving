#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string n;
    cin >> n;
    if(n.length() > 3){
        for (int i = n.length() - 3; i > 0; i-=3)
        {
            n.insert(i,1,',');
            // i -= 1;
        }
    }
    cout << n;
    
    return 0;
}