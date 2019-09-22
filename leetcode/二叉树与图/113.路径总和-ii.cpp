/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 * 思路：先序遍历，回溯
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        if (!root) {
            return result;
        }
        generate(root, sum, result, temp);
        return result;

    }
private:
    void generate(TreeNode* root, int sum,
                  vector<vector<int>>& result,
                  vector<int>& temp) {
        sum -= root->val;
        temp.push_back(root->val);

        if (sum == 0 && root->left == NULL && root->right == NULL) {
            result.push_back(temp);
            return;
        }

        if (root->left) {
            generate(root->left, sum, result, temp);
            temp.pop_back();
        }

        if (root->right) {
            generate(root->right, sum, result, temp);
            temp.pop_back();
        }
        
    }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        int path_value = 0;
        preorder(root, path_value, sum, path, result);
        return result;

    }
private:
    void preorder(TreeNode* node, int& path_value, int sum,
                  vector<int>& path,
                  vector<vector<int>> & result) {
        if (!node) {
            return;
        }
        path_value += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && sum == path_value) {
            result.push_back(path);
        }
        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);
        path_value -= node->val;
        path.pop_back();
    }
};
