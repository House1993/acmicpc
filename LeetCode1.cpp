//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54287279
 */

/**
 * map implementation
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> num_to_idx;
        for (int i = 0; i < nums.size(); ++i) {
            num_to_idx[nums[i]] = i;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_to_idx.count(target - nums[i]) && num_to_idx[target - nums[i]] != i) {
                res.push_back(i);
                res.push_back(num_to_idx[target - nums[i]]);
                break;
            }
        }

        return res;
    }
};

/**
 * multimap implementation
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        multimap<int, int> num_to_idx;
        for (int i = 0; i < nums.size(); ++i) {
            num_to_idx.insert(make_pair(nums[i], i));
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_to_idx.count(target - nums[i])) {
                for (multimap<int, int>::iterator it = num_to_idx.lower_bound(target - nums[i]);
                     it != num_to_idx.end() && it->first == target - nums[i]; ++it) {
                    if (it->second != i) {
                        res.push_back(i);
                        res.push_back(it->second);
                        return res;
                    }
                }
            }
        }

        return res;
    }
};