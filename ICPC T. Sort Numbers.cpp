#include <iostream>
using namespace std;

int checkMax(int a, int b, int c){
    if(a > b){
        if(a > c) return a;
        else return c;
    } 
    else if (b > c) return b;
    else return c;
}

int checkMin(int a, int b, int c){
    if(a < b){
        if (a < c) return a;
        else return c;
    }
    else if (b < c) return b;
    else return c;
}

int checkMid(int a, int b, int c){
    if(a > b){
        if(a < c) return a;
        else if (c > b) return c;
        else return b;
    } 
    else if (c > b) return b;
    else if (c > a) return c;
    else return a;
}

int main(){
    long long a, b, c; 
    cin >> a >> b >> c;
    long long max = checkMax(a,b,c), min = checkMin(a,b,c), mid = checkMid(a,b,c);

    cout << min << endl << mid << endl << max << endl << endl;
    cout << a << endl << b << endl << c << endl;

    return 0;
}