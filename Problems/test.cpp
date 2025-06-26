#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n == 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<pii> getPrimeFactors(int n) {
    vector<pii> primeFactors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            primeFactors.push_back({i, count});
        }
    }
    if (n > 1) primeFactors.push_back({n, 1});
    return primeFactors;
}

vi getDivisors(int n) {
    vi divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    return divs;
}

int pow(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = result * a;
        a = a * a;
        b /= 2;
    }
    return result;
}

int powmod(int a, int b, int m) {
    a %= m;
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

int main() {

    return 0;
}
