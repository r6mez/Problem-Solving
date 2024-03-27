#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long


string add9999(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) 
    {
        int x = (i >= 0) ? num1[i] - '0' : 0;
        int y = (j >= 0) ? num2[j] - '0' : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        sum %= 10;
        result = to_string(sum) + result;
        i--;
        j--;
    }

    return result;
}

string multiplyBy9999(string s, int digit) {
    string result = "";
    int carry = 0;

    for (int i = s.size() - 1; i >= 0; i--) 
    {
        int product = (s[i] - '0') * digit + carry;

        carry = product / 10;
        product %= 10;
        result = to_string(product) + result;
    }

    while (carry > 0) 
    {
        result = to_string(carry % 10) + result;
        carry /= 10;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s; cin >> s;
    cout << add9999(s, "9999") << "\n" << multiplyBy9999(s, 9999);
    return 0;
}
