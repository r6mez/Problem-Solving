#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    long long numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers+n);

    for (int i = 0; i < q; i++)
    {
        long long x;
        cin >> x;
        if(binary_search(numbers,numbers+n,x)) cout << "found\n";
        else cout << "not found\n";
    }
    
    return 0;
}