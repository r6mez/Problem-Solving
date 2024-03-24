#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n); 
    vector<int> lights(n, 0);
    int moments = 0;
    int max_number = -1;
    int blue_bulbs = 0; 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        lights[arr[i] - 1] = 1; 
        max_number = max(max_number, arr[i] - 1);

        if (max_number == i) {
           
            moments++;
            blue_bulbs = max_number + 1; 
        }
    }

    cout << moments;

    return 0;
}
