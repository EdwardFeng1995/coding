// 题目：两个链表的第一个公共节点
// 输入两个链表，找出它们的第一个公共结点
//
// 思路1
// 从后往前比，最后一个相同节点就是，但是需要辅助存储，浪费空间
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        vector<ListNode*> vec1;
        vector<ListNode*> vec2;
        ListNode *temp1 = pHead1;
        ListNode *temp2 = pHead2;
        while(temp1) {
            vec1.push_back(temp1);
            temp1 = temp1->next;
        }
        while(temp2) {
            vec2.push_back(temp2);
            temp2 = temp2->next;
        }
        int i = vec1.size()-1, j = vec2.size()-1;
        ListNode *res = NULL;
        for (i, j; i >=0&&j>=0; i--, j--) {
            if (vec1[i] == vec2[j]) {
                res = vec1[i];
                continue;
            } else {
                return res;
            }
        }
        return res;
    }
};

// 思路2
// 1.计算headA链表长度，计算headB链表长度，较长的链表多出的长度。
// 2.将较长链表的指针移动到和较短链表指针对齐的位置
// 3.headA与headB同时移动，当两指针指向同一节点时，即找到了。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *temp1 = pHead1;
        ListNode *temp2 = pHead2;
        int len1 = 0, len2 = 0;
        while(temp1) {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            len2++;
            temp2 = temp2->next;
        }
        temp1 = pHead1;
        temp2 = pHead2;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 && temp2) {
            if (temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
