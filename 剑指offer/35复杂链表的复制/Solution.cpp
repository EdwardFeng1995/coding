// 题目：复杂链表的复制
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
// 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
//
// 思路1：用map保存原链表地址和位置的关系<RandomListNode*, int>，在设置新链表random的时候可以从map中查找
//
// 思路2：降低空间复杂度，每复制一个节点，就连在原节点后面，在random可以通过原节点node->random->next找到
//

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, int> node_map;
        vector<RandomListNode*> node_vec;
        int i = 0;
        RandomListNode* ptr = pHead;
        while (ptr) {
            RandomListNode* node = new RandomListNode(ptr->label);
            node_vec.push_back(node);
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(NULL);
        ptr = pHead;
        i = 0;
        while (ptr) {
            node_vec[i]->next = node_vec[i+1];
            if (ptr->random) {
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        Connect_random(pHead);
        return Connect(pHead);
    }
    void CloneNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while (pNode) {
            RandomListNode* pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }
    void Connect_random(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while (pNode) {
            RandomListNode* pClone = pNode->next;
            if (pNode->random) {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }
    RandomListNode* Connect(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        RandomListNode* pCloneNode = NULL;
        if (pNode) {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        while (pNode) {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
};

