#include <iostream>
#include <bitset>

using namespace std;

bool isOdd(int n){
    if(n%2 != 0) return true;
    else return false;
}

string toBinary(int n){
    string binary = "";
    while (n){
        binary = to_string(n%2) + binary;
        n = n / 2;
    }
    return binary;
}

bool isBinaryPilndrome(int n)
{
    string binary = toBinary(n);
    int isPil = true;
    for (int i = 0; i < binary.length()/2; i++)
    {   
        if(binary[i] != binary[binary.length()-i-1]) isPil = false;
    }

    return isPil;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n; 
    cin >> n;
    if(isOdd(n) && isBinaryPilndrome(n)) cout << "YES";
    else cout << "NO";
    return 0;
}