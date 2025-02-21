/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// K. Max and Min
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K
// Time: 2/21/2025, 1:51:48 PM
#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    
    if (A <= B && A <= C)
        cout << A << ' ';
    else if (B <= A && B <= C)
        cout << B << ' ';
    else
        cout << C << ' ';

    if (A >= B && A >= C)
        cout << A << ' ';
    else if (B >= A && B >= C)
        cout << B << ' ';
    else
        cout << C << ' ';
}

