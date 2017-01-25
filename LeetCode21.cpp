//
// Created by 房籽呈 on 2017/1/24.
//

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *ans, *head;
        if (l1->val <= l2->val) {
            ans = head = l1;
            l1 = l1->next;
        } else {
            ans = head = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if (l1 != NULL && l2 == NULL) {
            head->next = l1;
        } else if (l1 == NULL && l2 != NULL) {
            head->next = l2;
        }

        return ans;
    }
};