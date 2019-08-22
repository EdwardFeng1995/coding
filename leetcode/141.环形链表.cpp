/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 * 思路：方法1：笨办法
 *       遍历链表，将节点插入到set中。
 *       在遍历时，插入节点前，需要在set中查找，第一个在set中发现的节点地址,即是链表环的起点。
 *
 *       方法2：快慢指针法
 *       一个慢指针，一个快指针，快指针移动速度是慢指针的两倍，当快指针与慢指针相遇时(有环)，记为meet
 *       分别从head与meet出发，速度一样，head与meet相遇即为环的起点
 *
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
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false; 
    }
};

// 方法2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = NULL;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

