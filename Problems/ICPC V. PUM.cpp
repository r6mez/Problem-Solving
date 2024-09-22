#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int i = 1;
    while (n--)
    {
        cout << i++ << " " << i++ << " " << i++ << " PUM" << endl;
        i++;
    }
    return 0;
}