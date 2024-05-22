#include <iostream>
using namespace std;

string getCorrectWord(const string& word) {
    int a_start = 0, a_len = 0;
    int b_start = -1, b_len = 0;
    string dest = { word.at(0) };

    for (int i = 1; i < word.size(); ++i) {
        if (word[i] == word[a_start]) {
            a_len = i - a_start + 1;
            if (a_len == 2) {
                dest.append(1, word[i]);
            }
        }
        else {
            if (2 == a_len) {
                if (-1 == b_start) {
                    b_start = i;
                    b_len = 1;
                    dest.append(1, word[i]);
                }
                else if (word[i] != word[b_start]) {
                    a_start = i;
                    b_start = -1;
                    dest.append(1, word[i]);
                }
            }
            else {
                a_start = i;
                dest.append(1, word[i]);
            }
        }
    }

    return dest;
}

int main() {
    int total;
    string word;
    while ( cin >> total ) {
        while (total--) {
            cin >> word;
            cout << getCorrectWord(word);
        }
    }
}