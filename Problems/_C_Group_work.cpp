// didn't work
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long groups = pow(2, n) - n - 1;
    cout<<groups;
}