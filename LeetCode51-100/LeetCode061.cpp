//
// Created by 房籽呈 on 2017/5/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72765032
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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *tail;
        int n = 0;
        for (ListNode *i = head; i != NULL; i = i->next) {
            ++n;
            tail = i;
        }
        if (n == 0 || k % n == 0) {
            return head;
        }
        k = n - k % n;
        ListNode *it = head;
        for (int i = 1; i < k; ++i) {
            it = it->next;
        }
        ListNode *ot = it->next;
        it->next = NULL;
        tail->next = head;
        return ot;
    }
};