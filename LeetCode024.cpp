//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题意：
 * http://blog.csdn.net/houserabbit/article/details/54783052
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *ans, *bef, *f1, *f2;
        f1 = head;
        f2 = head->next;
        f1->next = f2->next;
        f2->next = f1;
        ans = f2;
        bef = f1;
        for (f1 = bef->next; f1 != NULL; f1 = bef->next) {
            f2 = f1->next;
            if (f2 == NULL) {
                break;
            }
            f1->next = f2->next;
            f2->next = f1;
            bef->next = f2;
            bef = f1;
        }
        return ans;
    }
};