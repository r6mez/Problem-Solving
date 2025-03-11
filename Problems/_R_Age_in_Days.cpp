#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int years, months, days;
    years = n/365;
    n = n % 365;
    months = n / 30;
    n = n % 30;
    days = n;

    cout << years << " years" << endl;
    cout << months << " months" << endl;
    cout << days << " days" << endl;
    return 0;
}