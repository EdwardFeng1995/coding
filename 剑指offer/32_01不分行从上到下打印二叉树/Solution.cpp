// 题目：不分行从上到下打印二叉树
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};
