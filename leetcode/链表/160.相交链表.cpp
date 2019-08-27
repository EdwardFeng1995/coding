/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 思路：
 *      方法1：使用set求交集
 *             1.遍历链表A，将A中节点对应的指针（地址）插入set
 *             2.遍历链表B，将B中节点对应的指针（地址）在set中查找，
 *             发现set中的第一个节点地址，即是两个链表的交点。
 *             时间复杂度O(m+n), 空间复杂度O(m)或O(n).
 *
 *      方法2：1.计算headA链表长度，计算headB链表长度，较长的链表多出的长度。
 *             2.将较长链表的指针移动到和较短链表指针对齐的位置
 *             3.headA与headB同时移动，当两指针指向同一节点时，即找到了。
 *             时间复杂度O(n)，空间复杂度O(1)。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1：
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> node_set;
        while(headA) {
            node_set.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if (node_set.find(headB) != node_set.end())
                return headB;
            headB = headB->next;
        }
        return NULL;

    }
};


// 方法2：
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB); // 求A，B两个链表的长度
        if (list_A_len > list_B_len)
            headA = forward_long_list(list_A_len, list_B_len, headA);
        else
            headB = forward_long_list(list_B_len, list_A_len, headB);
        while(headA && headB) {
            if (headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
private:
    // 获得链表长度
    int get_list_length(ListNode* head) {
        int len = 0;
        while(head) { // 遍历链表，计算链表长度
            len++;
            head = head->next;
        }
        return len;
    }

    // 长的链表头结点向前移动
    ListNode* forward_long_list(int long_len, int short_len, ListNode* head) {
        int delta = long_len - short_len;
        while(head && delta) {
            head = head->next;
            delta--;
        }
        return head;
    }
};

