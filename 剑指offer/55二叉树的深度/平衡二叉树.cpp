// 题目：平衡二叉树
// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced_Solution(pRoot, depth);
    }
    bool IsBalanced_Solution(TreeNode* pRoot, int &depth) {
        if (pRoot == NULL) {
            depth = 0;
            return true;
        }
        int left = 0, right = 0;
        if (IsBalanced_Solution(pRoot->left, left) &&
            IsBalanced_Solution(pRoot->right, right)) {
            int diff = left - right;
            if (diff <= 1 && diff >= -1) {
                depth = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
};
