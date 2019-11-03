/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            ListNode* temp1 = temp->next;
            if (temp1) {
                while (temp1->val == temp->val) {
                    temp1 = temp1->next;
                    if (temp1 == NULL)
                        break;
                }
            }
            temp->next = temp1;
            temp = temp1;
        }
        return head;
    }
};
// @lc code=end

