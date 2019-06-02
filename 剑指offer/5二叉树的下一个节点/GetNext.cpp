// 二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
// 思路：如果一个节点有右子树，那么下一个节点就是右子树中最左子节点
//      如果一个节点的右子树为空，分两种情况，如果该节点是父节点的左子节点，则下一个节点就是父节点
//      如果该节点是是父节点的右子节点，沿着父节点的指针向上遍历，直到找到一个是它父节点的左子节点的节点，
//      如果存在，则这个节点的父节点即为要找的下一个节点


/*
struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
    BinaryTreeNode*        m_pParent;
};
*/

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) 
{
    if (pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;
    if (pNode->m_pRight != nullptr) {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr) {
            pRight = pRight->m_pLeft;
        }

        pNext = pRight;
    } else if (pNode->m_pParent != nullptr) {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }
    return pNext;
}