/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 * 方法1：递归，将大问题分为子问题
 * 返回值：交换完成的子链表。
 * 调用单元：设需要交换的两个点为head和next， head连接后面交换完成的子链表，next连接head，完成交换
 * 终止条件：head为空指针或者next为空指针，也就是当前无节点或者只有一个节点，无法进行交换。
 *
 * 方法2：
 * 添加一个哑节点dummy，其next指针指向head。定义三个指针pre，cur，next
 * 初始化：pre = head; cur = pre->next; next = cur->next;
 * 交换：pre->next = next;
 *       cur->next = next->next;
 *       next->next = cur;
 * 更新：pre = cur;
 *       cur = cur->next;
 *       next = cur->next;
 * 
 * 方法3：
 * 遍历，两两交换，将交换到前面的节点存到vector，待都交换完后，重新连接一下。
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};


// 方法2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        pre->next = head;
        ListNode* cur = head;

        while (cur) {
            ListNode* next = cur->next;
            if (next == NULL)
                break;

            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

// 方法3
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int i = 0;
        int j = 1;
        std::vector<ListNode*> node_vec;
        ListNode* temp1 = head;
        while (temp1 && temp1->next != NULL) {
            node_vec.push_back(temp1->next);
            ListNode* tnn = temp1->next->next;
            temp1->next->next = temp1;
            temp1->next = tnn;
            temp1 = temp1->next;
        }
        temp1 = head;
        while (temp1) {
            if (i % 2 == 0) {
                if (j < node_vec.size()) {
                    temp1->next = node_vec[j];
                    j++;
                } else {
                    break;
                }
            }
            temp1 = temp1->next;
            i++;
        }
        return node_vec[0];
    }
};
