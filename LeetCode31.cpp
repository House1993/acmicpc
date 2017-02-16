//
// Created by house on 2/16/17.
//

/**
 * 题意：
 * http://blog.csdn.net/houserabbit/article/details/55259652
 */

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int idx = findPos(nums);
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            reverse(nums.begin() + idx + 1, nums.end());
            for (int i = idx + 1; i < nums.size(); ++i) {
                if (nums[idx] < nums[i]) {
                    swap(nums[idx], nums[i]);
                    break;
                }
            }
        }
    }

private:
    int findPos(vector<int> &nums) {
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * 偷懒版本……
 */

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
    }
};