#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void get_sums(int index, const vector<int> &weights, int sum, const vector<int> &counts,
              set<int> &sums) {
    if (index == weights.size()) {
        sums.insert(sum);
        return;
    }

    int single_weight = weights.at(index);
    int count = counts.at(index);
    for (int n = 0; n < count + 1; ++n) {
        get_sums(index + 1, weights, sum, counts, sums);
        sum += single_weight;
    }
}

void get_sums_bfs(int num, const vector<int>& weights, vector<int>& counts) {
    queue<pair<int,int> > queue; // index, value

    // init
    int i;
    int weight = weights[0];
    for (i = 0; i < counts.at(0); ++i) {
        queue.push(make_pair(0, weight));
        weight += weights[0];
    }

    set<int> sums;
    pair<int,int> node;
    while(!queue.empty()) {

        node = queue.front();
        queue.pop();

        // process
        if (sums.find(node.second) == sums.end()) {
            sums.insert(node.second);
        }

        // add node
    }
}

int main() {
    int num;
    int value;
    int i;
    while (cin >> num) {
        vector<int> weights;
        vector<int> counts;
        set<int> sums;

        for (i = 0; i < num; ++i) {
            cin >> value;
            weights.push_back(value);
        }

        for (i = 0; i < num; ++i) {
            cin >> value;
            counts.push_back(value);
        }

        get_sums(0, weights, 0, counts, sums);
        cout << sums.size();
    }

    return 0;
}