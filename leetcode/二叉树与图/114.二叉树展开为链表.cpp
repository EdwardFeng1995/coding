/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * 思路1：
 * 对树做先序遍历，每个节点存到vector，然后再接起来，但是不符合题目的in-place要求
 *
 * 思路2：
 * 递归，递归函数要传出生成的链表的最后一个节点，因为要接右子树生成的链表
 *
 * 思路3：
 * 后序遍历加递归，
 * 变形的后序遍历，先右，后左，再根，6 5 4 3 2 1
 * 每遍历一个节点，就将当前节点的右指向前一个节点
 * 遍历到5，5的右指向6，6<-5  4 3 2 1
 * 遍历到4，4的右指向5，6<-5<-4 3 2 1
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 思路1：
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> temp;
        preorder(root,temp);
        for (int i = 0; i < temp.size(); i++) {
            if (i == temp.size() - 1) {
                break;
            }
            temp[i]->right = temp[i+1];
            temp[i]->left = NULL;
        }
    }
private:
    void preorder(TreeNode* root,
                  vector<TreeNode*>& temp) {
        if (!root) {
            return;
        }
        temp.push_back(root);
        preorder(root->left, temp);
        preorder(root->right, temp);
    }
};


// 思路2：
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        preorder(root, last);
    }
private:
    void preorder(TreeNode* root, TreeNode*& last) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            last = root;
            return;
        }
        TreeNode* left = root->left;    // 备份左右指针
        TreeNode* right = root->right;
        TreeNode* left_last = NULL;     // 左右子树最后一个节点
        TreeNode* right_last = NULL;    // 左右子树最后一个节点
        // 递归左子树，将左子树展开成链表
        if (left) {
            preorder(left, left_last);
            root->left = NULL;
            root->right = left;
            last = left_last;
        }
        // 递归右子树
        if (right) {
            preorder(right, right_last);
            if (left_last) {              // 若有左子树，左子树链表的最后一个节点接右子树
                left_last->right = right;
            }
            right->left = NULL;
            last = right_last;
        }
    }
};


// 思路3
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        flatten(root->right);  // 先递归右子树， 1-2-3-4-5-6变为6-5-4-3-2-1
        flatten(root->left);
        root->right = pre;     // 当前节点的右指向前一节点
        root->left = NULL;
        pre = root;
    }
private:
    TreeNode* pre = NULL;
};
