//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72764544
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> presum;
        vector<int> factorial;
        for (int i = 0; i <= n; ++i) {
            presum.push_back(i);
            if (i) {
                factorial.push_back(factorial[i - 1] * i);
            } else {
                factorial.push_back(1);
            }
        }
        stringstream ss;
        for (int i = 0; i < n; ++i) {
            for (int j = n; j > 0; --j) {
                if (presum[j] - presum[j - 1] && k > factorial[n - i - 1] * (presum[j] - 1)) {
                    ss << j;
                    k -= factorial[n - i - 1] * (presum[j] - 1);
                    for (int o = j; o <= n; ++o) {
                        --presum[o];
                    }
                    break;
                }
            }
        }
        return ss.str();
    }
};