#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;

    int numberOfZeros = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0){
            numberOfZeros++;
        } else {
            cout << x << " ";
        }
    }
    for (int i = 0; i < numberOfZeros; i++)
    {
        cout << 0 << " ";
    }

    return 0;
}