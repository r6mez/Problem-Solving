#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s) {
        list<char> result;
        auto cursor = result.begin();
        for (char ch : s) {
            if (ch == '[') {
                cursor = result.begin();
            } else if (ch == ']') {
                cursor = result.end();
            } else {
                cursor = result.insert(cursor, ch);
                cursor++;
            }
        }
        for (auto ch : result) {
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}