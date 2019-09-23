/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 * 思路1：递归，简单
 * 思路二：用栈迭代，以防万一，万一要求不能使用递归
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

// 思路1：递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        inorder(root, re);
        return re;
    }
private:
    void inorder(TreeNode* root, vector<int>& re) {
        if (!root) {
            return;
        }
        inorder(root->left, re);
        re.push_back(root->val);
        inorder(root->right, re);
    }
};


//思路2：用栈的迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur || !stack.empty()) {
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            re.push_back(cur->val);
            cur = cur->right;
        }
        return re;
    }

};

