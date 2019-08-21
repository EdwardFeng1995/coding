/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 * 思路：寻找关键节点。
 *       反转段头节点的前驱，
 *       反转前头结点->反转后尾节点，
 *       反转前尾节点->反转后头节点
 *       反转段尾节点的后继。
 * 步骤：1.将head向前移动m-1个位置，找到开始反转的节点，记录该节点的前驱和该节点。
 *       2.从head开始，反转n-m+1个节点
 *       3.将pre_head与new_head连接，modify_list_tail与head连接。
 *       4.若m等于1，直接返回new_head;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n -m +1;   // 计算需要反转的节点个数
        ListNode* pre_head = NULL;  // 用来存储开始反转的节点的前驱
        ListNode* result = head;    // 存储原链表的头结点，如果不是从第一个节点开始反转，head会往后移
        while(head && --m) {        // 将head向前移动m-1个位置，指向开始反转的节点
            pre_head = head;        // 记录head的前驱
            head = head->next;
        }
        
        ListNode* modify_list_tail = head;  // 指向当前的head，即反转后的链表尾
        ListNode* new_head = NULL;
        ListNode* temp;
        while (head && change_len) {
            temp = head->next;
            head->next = new_head;
            new_head = head;
            head = temp;
            change_len--;
        }
        modify_list_tail->next = head;  // 连接反转后的链表尾与反转段的后一个节点
        if (pre_head) {  //如果pre_head不为空，说明不是从第一个节点开始反转的，m>1
            pre_head->next = new_head;       // 原来开始反转的节点的前驱指向反转后的头结点
        } else {
            result = new_head;  // 说明m从第一个节点反转，新节点就是反转后的头结点
        }
        return result;
    }
};

