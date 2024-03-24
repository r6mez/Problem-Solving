#include <iostream>
#include <iomanip>  
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    double numbers[n];
    
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
    }
     
    double average = sum / n; 
    cout << fixed << setprecision(7) << average;
    return 0;
}