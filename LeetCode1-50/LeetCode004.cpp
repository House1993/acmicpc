//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54287753
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (!nums1.size()) {
            int len = nums2.size();
            return (double) (nums2[len / 2] + nums2[(len - 1) / 2]) / 2;
        }
        if (!nums2.size()) {
            int len = nums1.size();
            return (double) (nums1[len / 2] + nums1[(len - 1) / 2]) / 2;
        }

        int ans1 = -1, ans2 = -1, change = 0, n = nums1.size() + nums2.size();;

        getans(nums1, nums2, &ans1, &ans2, n);
        if (ans1 == -1) {
            change = 1;
            swap(nums1, nums2);
            getans(nums1, nums2, &ans1, &ans2, n);
        }

        printf("%d %d %d \n", change, ans1, ans2);
        if (n & 1) {
            return nums1[ans1];
        }
        if (!ans2) {
            return (double) (nums1[ans1] + nums1[ans1 - 1]) / 2;
        } else {
            if (nums1[ans1 - 1] >= nums2[ans2 - 1]) {
                return (double) (nums1[ans1] + nums1[ans1 - 1]) / 2;
            } else {
                return (double) (nums1[ans1] + nums2[ans2 - 1]) / 2;
            }
        }
    }

private:
    void getans(vector<int> &nums1, vector<int> &nums2, int *ans1, int *ans2, int n) {
        int l = 0, r = nums1.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int idxl = lower_bound(nums2.begin(), nums2.end(), nums1[m]) - nums2.begin();
            int idxr = upper_bound(nums2.begin(), nums2.end(), nums1[m]) - nums2.begin();
            if (m + idxl <= n / 2 && m + idxr >= n / 2) {
                *ans1 = m;
                *ans2 = n / 2 - m;
                break;
            } else if (m + idxr < n / 2) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
};