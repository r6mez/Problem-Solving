#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<vector>
#define  sv vector<string> 
using namespace std;
int main()
{
    int n; cin >> n;
    sv tags(n);

    for (int i = 0;i < n;i++) { cin >> tags[i]; }

    //check if the first tag is not header or the last tag is not endheader
    if (tags[0] != "Header" || tags[n - 1] != "EndHeader") {
        cout << "WA" << endl;
        return 0;
    }

    // int hdrCount = count(tags.begin(), tags.end(), "Header");
    // int endHdrCount = count(tags.begin(), tags.end(), "EndHeader");
    // if (hdrCount != 1 || endHdrCount != 1) {
    //     cout << "WA\n";
    //     return 0;
    // }

    stack<string> s;

    auto match = [](const string& endTag)
        {
            if (endTag == "EndHeader") return "Header";
            if (endTag == "EndTable") return "Table";
            if (endTag == "EndRow")  return "Row";
            if (endTag == "EndCell") return "Cell";
            return "";
        };

    for (const string& tag : tags)
    {
        if (tag == "Header" || tag == "Table" || tag == "Row" || tag == "Cell") {
            s.push(tag);
        }
        else
        {
            if (s.empty() || s.top() != match(tag)) {
                cout << "WA" << endl;
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty())
        cout << "ACC" << endl;
    else
        cout << "WA" << endl;

    return 0;
}