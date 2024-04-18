#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int range = 1000;
int composite_table[range + 1] = {0};
vector<int> primes;
void init_primes() {
    int num ;
    for (int i = 2; i < range + 1; ++i) {
        if (!composite_table[i]) {
            primes.push_back(i);
        }

        for (int p : primes) {
            num = p * i;
            if (num > range) { break;}
            composite_table[num] = 1;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void get_least_diff(int num) {
    int m,n;
    int rm, rn; // no need to record min_diff
    for (m = 2; m <= num / 2; ++m) { // num / 2 is ok
        int n = num - m;
        if (!composite_table[m] &&
            !composite_table[n]) {
                rm = m;
                rn = n;
        }
    }

    cout << rm << endl;
    cout << rn << endl;
}

int main() {
    int n;
    init_primes();
    while (cin >> n) {
        get_least_diff(n);
    }
    
}