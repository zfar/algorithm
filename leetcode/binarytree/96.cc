class Solution {
public:
    int numTrees(int n) {
        if (0 == n || 1 == n) {
            return 1;
        }

        int ret = 1;
        for (int i = n + 2; i < 2 * n; ++i) {
            ret *= i;
        }
        ret *= 2; // 2n / n

        int denominator = 1;
        for (int i = 2; i < n; ++i) {
            denominator *= i;
        }
        return ret / denominator;
    }
};