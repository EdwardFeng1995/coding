// 题目：二叉搜索树的第K大节点
// 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k == 0) return NULL;
        return midorder(pRoot, k);
    }
    
    TreeNode* midorder(TreeNode* node, int &k) {
        TreeNode *res = NULL;
        if (node->left) 
            res = midorder(node->left, k);
        if (res == NULL) {
            if (k == 1)
                res = node;
            k--;
        }
        if (res == NULL && node->right)
            res = midorder(node->right, k);
        return res;
    }
    
};
