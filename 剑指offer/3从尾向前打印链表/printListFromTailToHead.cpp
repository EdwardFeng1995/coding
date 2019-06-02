// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
//
// 思路：因为是单向链表，所以正向打印很方便，若反向打印，则可以考虑将节点（或节点值）存入
// “先进后出”的栈结构中，最后再从栈中依次取出。

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ArrayList;
        std::stack<ListNode*> nodes;
        
        ListNode* pnode = head;
        while(pnode != nullptr) {
            nodes.push(pnode);
            pnode = pnode->next; 
        }
        
        while(!nodes.empty()) {
            pnode = nodes.top();
            ArrayList.push_back(pnode->val);
            nodes.pop();
        }
        return ArrayList;
    }
};
