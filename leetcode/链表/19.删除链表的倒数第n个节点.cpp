/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 * 思路：
 * 方法1：两次遍历
 * 删除从列表开头数起的第 (L - n + 1)个结点，其中L 是列表的长度。只要我们找到列表的长度L，这个问题就很容易解决。
 * 首先我们将添加一个哑结点作为辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。
 * 在第一次遍历中，找出列表长度L，再设一个指向哑节点的指针，并移动它遍历列表找到要删除的节点。
 * 时间复杂度：O(L)， 空间复杂度：O(1)
 *
 * 方法2：一次遍历
 * 设置两个指针指向哑结点，第一个指针移动n+1步，第二指针开始移动，此时两个指针相距n个节点，
 * 第1个指针移动到最后一个节点，第二个指针刚好指向从最后一个节点数起的第n个节点。
 * 时间复杂度：O(L),   空间复杂度：O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        } 
        len -=n;
        temp = &dummy;
        while (len > 0) {
            len--;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return dummy.next;
    }
};

// 方法2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        for (int i = 1; i <= n+1; i++) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
};
