#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;

int dfs(const vector<vector<int> > moneys, int time, int n, int city_index, int time_left, int& sum) {
    if (city_index = moneys.size()) {

    }

    for (int i = 0; i < time; ++i) {

    }
    return 0;
}

int calc_money(int time, int n, const vector<int>& init_m, const vector<int>& des) {
    if (0 == time) {
        return 0;
    }

    vector<vector<int> > moneys;
    for (int i = 0; i < n; ++i) {
        vector<int> city_moneys = {0};
        int init = init_m[i];
        int d = des[i];
        int money = init;
        for (int j = 1; j < time + 1; ++j) {
            if (money != 0) {
                city_moneys.push_back(money);
                money -= d;
            }
            else {
                city_moneys.push_back(0);
            }
        }
    }

    int sum = 0;
    return dfs(moneys, time, n, 0, time, sum);
}

// 10 2   // 时间，A城到B城中间的城市数 
// 1 1 2  // 到各城市需要的天数; 这些城市之间是 线性 的，不是图
// 200 5  // 中间城市，第一天赚的钱数，和每天递减的数量
// 90 10
int main() {
    int t, n;
    int val;
    while (cin >> t >> n) {
        int tmp = n + 1;
        int road_time = 0;
        vector<int> init_m;
        vector<int> d;
        while(tmp--) {
            cin >> val;
            road_time += val;
        }
        tmp = n;
        while(tmp--) {
            cin >> val;
            init_m.push_back(val);
            cin >> val;
            d.push_back(val);
        }

        cout << calc_money(t - road_time, n, init_m, d) << endl;
    }
    return 0;
}