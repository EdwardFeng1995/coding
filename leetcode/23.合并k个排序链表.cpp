/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 * 思路：
 * 方法1：将k*n个节点放到vector中，再将vector排序，再将节点顺序相连 。
 *        时间复杂度：k个链表，平均每个链表n个节点，KN×logKN + KN = O(KN*logKN)
 * 
 * 方法2：分治归并
 *        对k个链表进行分治，两两进行合并，可以利用递归。
 *        时间复杂度：k个链表，平均每个链表n个节点，
 *                    第一轮，进行k/2次，每次处理2n个值
 *                    第二轮，进行k/4次，每次处理4n个值
 *                    最后一轮，进行k/(2^logk)次，每次处理2^logk*n个值
 *                    2n*k/2 + 4n*k/4 + ... + 2^logk*n*k/(2^logk) = nk + nk + ... = O(nklogk)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }
        int mid = lists.size()/2;

        std::vector<ListNode*> sub1_lists;
        std::vector<ListNode*> sub2_lists;
        for (int i = 0; i < mid; i++) {
            sub1_lists.push_back(lists[i]);
        } 
        for (int i = mid; i < lists.size(); i++) {
            sub2_lists.push_back(lists[i]);
        }
        ListNode* l1 = mergeKLists(sub1_lists);
        ListNode* l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1, l2);
    }

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

