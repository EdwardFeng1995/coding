// 题目：二叉搜索树与双向链表
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
//
// 先搞左子树，再搞右子树，pLastNodeInlist代表转换完的链表的最后一个节点
// 则pCurrent->left = pLastNodeInlist;
//   pLastNodeInlist->right = pCurrent;
//   pLastNodeInlist = pCurrent;
//

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNodeInlist = NULL;
        ConvertNode(pRootOfTree, pLastNodeInlist);
        TreeNode* pHeadOflist = pLastNodeInlist;
        while (pHeadOflist && pHeadOflist->left) {
            pHeadOflist = pHeadOflist->left;
        }
        return pHeadOflist;
    }
    void ConvertNode(TreeNode* pNode, TreeNode*& pLastNodeInlist) {
        if (!pNode) return;
        TreeNode* pCurrent = pNode;
        if (pCurrent->left) {
            ConvertNode(pCurrent->left, pLastNodeInlist);
        }
        pCurrent->left = pLastNodeInlist;
        if (pLastNodeInlist) {
            pLastNodeInlist->right = pCurrent;
        }
        pLastNodeInlist = pCurrent;
        if (pCurrent->right) {
            ConvertNode(pCurrent->right, pLastNodeInlist);
        }
    }
};
