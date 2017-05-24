//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54707915
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int m = 0;
        for (ListNode *it = head; it != NULL; it = it->next, ++m);
        m -= n;
        if (m == 0) {
            return head->next;
        }
        for (ListNode *it = head;; --m, it = it->next) {
            if (m == 1) {
                it->next = it->next->next;
                break;
            }
        }
        return head;
    }
};