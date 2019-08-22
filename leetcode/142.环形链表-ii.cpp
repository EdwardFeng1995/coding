/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 思路：与141一致
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> node_set;
        while(head) {
            if (node_set.find(head) != node_set.end()) {
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL; 
    }
};

// 方法2
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = NULL;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow) {
                meet = fast;
                break;
            }
        }
        if (!meet) {
            return NULL;
        }
        while(head) {
            if (head == meet) {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};

