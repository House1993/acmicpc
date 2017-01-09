//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54287441
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *it1 = l1, *it2 = l2, *last;
        int up = 0;
        while (it1 != NULL && it2 != NULL) {
            last = it1;
            it1->val += up + it2->val;
            up = it1->val / 10;
            it1->val %= 10;
            it1 = it1->next;
            it2 = it2->next;
        }
        if (it1 == NULL && it2 != NULL) {
            last->next = it2;
            while (up && it2 != NULL) {
                last = it2;
                it2->val += up;
                up = it2->val / 10;
                it2->val %= 10;
                it2 = it2->next;
            }
        } else if (it1 != NULL && it2 == NULL) {
            while (up && it1 != NULL) {
                last = it1;
                it1->val += up;
                up = it1->val / 10;
                it1->val %= 10;
                it1 = it1->next;
            }
        }
        if (up > 0) {
            last->next = new ListNode(up);
        }
        return l1;
    }
};