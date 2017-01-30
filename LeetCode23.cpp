//
// Created by 房籽呈 on 2017/1/24.
//


/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54783032
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector < ListNode * > qu;
        for (int i = 0; i < lists.size(); ++i) {
            while (lists[i] != NULL) {
                qu.push_back(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        if (qu.empty()) {
            return NULL;
        }
        sort(qu.begin(), qu.end(), cmp);
        for (int i = 0; i < qu.size() - 1; ++i) {
            qu[i]->next = qu[i + 1];
        }
        qu[qu.size() - 1]->next = NULL;
        return qu[0];
    }

private:
    static bool cmp(ListNode *f1, ListNode *f2) {
        return f1->val < f2->val;
    }
};

