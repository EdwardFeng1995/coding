/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> Stack;
        unordered_set<TreeNode*> _set;
        if (root) {
            Stack.push(root);
        }
        while (!Stack.empty()) {
            TreeNode* node = Stack.top();

            bool leftvisited = true, rightvisited = true;
            if (node->right && _set.find(node->right) == _set.end()) {
                rightvisited = false;
                Stack.push(node->right);
            }
            if (node->left && _set.find(node->left) == _set.end()) {
                leftvisited = false;
                Stack.push(node->left);
            }
            if (leftvisited && rightvisited) {
                re.push_back(Stack.top()->val);
                _set.insert(Stack.top());
                Stack.pop();
            }
        }
        return re;
    }
};

