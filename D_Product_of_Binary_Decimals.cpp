#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

bool isBinaryDecimal(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && digit != 1) return false;
        n /= 10;
    }
    return true;
}

string addOneToBinary(std::string binary) {
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '0') {
            binary[i] = '1';
            return binary;
        }
        binary[i] = '0';
    }
    return '1' + binary;
}


bool canBeRepresented(int n) {
    int binaryDecimal = 10;
    while (n != 1 && binaryDecimal <= n){
        while (n % binaryDecimal == 0) {
            n /= binaryDecimal;
        }
        binaryDecimal = stoi(addOneToBinary(to_string(binaryDecimal)));
    }
    return n == 1;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(isBinaryDecimal(n)){
            cout <<"YES" << "\n";
        } else {
            cout << (canBeRepresented(n)? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
