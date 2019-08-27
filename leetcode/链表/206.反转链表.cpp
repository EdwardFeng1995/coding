/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * 思路：依次遍历链表节点，每遍历一个节点即反转一个节点。
 *       1.备份head->next
 *       2.修改head->next
 *       3.移动head与new_head
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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        ListNode* next = NULL;
        while(head) {
            next = head->next;    // 备份head->next
            head->next = new_head;          // 更新head->next
            new_head = head;                // 移动new_head;
            head = next;
        }
        return new_head;
    }
};

