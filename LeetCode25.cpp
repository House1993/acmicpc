//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题意：
 * http://blog.csdn.net/houserabbit/article/details/54783074
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode *f[k];
        bool ans = false;
        for (ListNode *bef = head; bef != NULL; bef = f[0]) {
            int i = 0;
            for (ListNode *it = (bef == head) ? head : bef->next; i < k && it != NULL; ++i, it = it->next) {
                f[i] = it;
            }
            if (i != k) {
                break;
            }
            f[0]->next = f[k - 1]->next;
            for (i = 0; i < k - 1; ++i) {
                f[i + 1]->next = f[i];
            }
            if (!ans) {
                ans = true;
                head = f[k - 1];
            } else {
                bef->next = f[k - 1];
            }

            for (ListNode *it = head; it != NULL; it = it->next) {
                printf("%d ->", it->val);
            }
            printf("\n");

        }
        return head;
    }
};