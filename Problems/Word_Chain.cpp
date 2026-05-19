#include <bits/stdc++.h>
using namespace std;

vector<string> words;
unordered_set<string> seen;
string endWord;
vector<vector<string>> answer;

bool ok(string& w1, string& w2, int idx) {
    if (w1[idx] == w2[idx]) return false;
    for (int i = 0; i < w1.size(); i++) {
        if (i == idx) continue;
        if (w1[i] != w2[i]) return false;
    }
    return true;
}

void go(string& currWord, vector<string>& chain) {
    if (currWord == endWord) {
        answer.push_back(chain);
        return;
    }
    for (int i = 0; i < currWord.size(); i++) {
        for (string& word : words) {
            if (ok(currWord, word, i) && !seen.count(word)) {
                seen.insert(word);
                chain.push_back(word);
                go(word, chain);
                chain.pop_back();
                seen.erase(word);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string begin, end;
    cin >> begin >> end;

    words.resize(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    seen.clear();
    endWord = end;
    answer.clear();

    seen.insert(begin);
    vector<string> chain = {begin};
    go(begin, chain);

    cout << answer.size() << "\n";
    for (auto& path : answer) {
        cout << path.size() << "\n";
        for (auto& w : path) cout << w << " ";
        cout << "\n";
    }
}