#include <iostream>
#include<iomanip>
using namespace std;

int main(){
    cout << fixed << setprecision(9);
    const double pi = 3.141592653;
    double r;
    cin >> r;
    long double area = pi * r * r;
    cout << area; 
    return 0;
}