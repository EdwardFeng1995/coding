/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 * 思路：设置两个临时的头节点，less_head和more_head
 *       遍历链表，比x小的节点接到less_head，大的接到more_head;
 *       将两个拼接。
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);
        ListNode more_head(0); // 设置两个临时的头节点
        ListNode* less_ptr = &less_head;
        ListNode* more_ptr = &more_head;
        while(head) {
            if (head->val < x) {
                less_ptr->next = head;
                less_ptr = head;
            } else {
                more_ptr->next = head;
                more_ptr = head;
            }
            head = head->next;
        }
        less_ptr->next = more_head.next;
        more_ptr->next = NULL;   // 尾节点后要接空
        return less_head.next;
    }
};

