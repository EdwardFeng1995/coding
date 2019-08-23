/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 * 难点：新链表的随机指针要怎么连接。
 * 思路：建立两个map，
 *       第一个map存储原链表节点地址与位置的键值对
 *       第二个链表存储新链表节点位置与地址的键值对，可以用vector代替
 *       遍历原链表，在vector中插入新节点
 *       最后连接新链表next指针、random指针。
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp1 = head;
        std::map<Node*, int> map1;
        std::vector<Node *> node_vec;
        int i = 0;
        while(temp1) {
            node_vec.push_back(new Node(temp1->val, NULL, NULL));
            map1[temp1] = i;
            temp1 = temp1->next;   // 遍历链表
            i++;
        }
        node_vec.push_back(0);
        temp1 = head;
        i = 0;
        while(temp1) {
            node_vec[i]->next = node_vec[i+1];
            if (temp1->random) {
                int id = map1[temp1->random];
                node_vec[i]->random = node_vec[id];
            }
            temp1 = temp1->next;
            i++;
        }
        return node_vec[0];
    }
};

