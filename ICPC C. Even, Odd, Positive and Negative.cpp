#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    int even=0,odd=0,positive=0,negative=0;
    for (int i = 1; i <= n; i++)
    {
        int x; 
        cin >> x;
        if (x % 2 == 0) even++;
        else odd++;
        
        if(x>0) positive++;
        else if (x<0) negative++;
    }

    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << positive << endl;
    cout << "Negative: " << negative << endl;
    return 0;
}