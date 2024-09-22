#include <iostream>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	int ascii[128] = {0,0};

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ',' && s[i] != '{' && s[i] != '}' && s[i] != ' ')
		ascii[s[i]]++;
	}

	int counter = 0;
	
	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] != 0) {
			counter++;
		}
	}
	
	cout << counter;

	return 0;
}