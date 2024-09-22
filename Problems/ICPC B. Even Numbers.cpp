#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n != 1){
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0){
                cout << i << endl;
            }
        }
    } else {
        cout << -1;
    }
    return 0;
}