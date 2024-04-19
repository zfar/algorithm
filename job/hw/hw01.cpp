#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;

void break_line(string& str, vector<int>& nums) {
    int pos = 0;
    int n_pos = str.find(",");
    const char* data = str.c_str();
    while(n_pos != string::npos) {
        str[n_pos] = 0;
        nums.push_back(atoi(data + pos));
        pos = n_pos + 1;
        n_pos = str.find(",");
    }
    nums.push_back(atoi(data + pos));
}

int get_check_num(const vector<int>& ids, const set<int>& ids_set, const vector<vector<int> >& rels) {
    set<int> need_check;
    for (int i : ids) {
        vector<int> id_vec;
        set<int> looked;

        id_vec.push_back(i);
        looked.insert(i);
        int pos = 0;
        while(pos < id_vec.size()) {
            int id = id_vec[pos];

            // 扩展
            for (int j = 0; j < rels[i].size(); ++j) {
                if (id == j)
                    continue;
                if (rels[id][j] && looked.find(j) == looked.end()) {
                    id_vec.push_back(j);
                    looked.insert(j);
                    if (need_check.find(j) == need_check.end() && ids_set.find(j) == ids_set.end()) {
                        need_check.insert(j);
                    }
                }
            }

            ++pos;
        }

    }

    return need_check.size();
}

int main() {
    int n;
    string ids;
    while(cin >> n) {
        // input sicks
        vector<int> sicks;
        set<int> sicks_set;
        cin >> ids;
        break_line(ids, sicks);
        for (int i : sicks) {
            sicks_set.insert(i);
        }

        vector<vector<int> > rels;
        while(n--) {
            cin >> ids;
            vector<int> lines;
            break_line(ids, lines);
            rels.push_back(lines);
        }
        
        cout << get_check_num(sicks, sicks_set, rels) << endl;
    }
    return 0;
}