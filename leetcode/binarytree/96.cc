class Solution {
public:
    int numTrees(int n) {
        static int ret[20] = {0};
        
        ret[0] = ret[1] = 1;
        if (ret[n] != 0) {
            return ret[n];
        }

        if (ret[n -1] != 0) {
            return (4*n-2) * ret[n-1] / n + 1;
        }

        int i;
        for (i = 2; i < n + 1; ++i) {
            ret[i] = (4*i -2)*ret[i-1] / i +1;
        }
        return ret[n];
    }
};