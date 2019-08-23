/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 * 思路：比较l1和l2的节点，将较小的节点插入到pre指针后，移动较小节点对应的指针
 *       pre指针移动，始终指向尾。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp_head(0);
        ListNode* pre = &temp_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if (l1) {  // 如果l1有剩余
            pre->next = l1;
        }
        if (l2) {  // 如果l2有剩余
            pre->next = l2;
        }
        return temp_head.next;
    }
};

