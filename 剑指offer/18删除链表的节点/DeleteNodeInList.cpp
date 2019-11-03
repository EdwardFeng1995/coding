// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

// 思路：传统的删除链表节点，temp->next->val = node->val; temp->next = temp->next->next;
// 传统方法需要直到要删除节点的前一个节点，需要遍历，时间复杂度O(n)
// 本题要求时间复杂度O（1），如果被删除节点不是尾节点，则用要删除节点的下一节点覆盖要删除的节点
// node->val = node->next->val;
// node->next = node->next->next;
// 如果要删除的是尾节点，则还是需要遍历得到尾节点的前一个节点
// 总的平均时间复杂度为[(n-1)O(n)+O(n)]/n
//
// 本题类似与leetcode237，但那道题是阅读理解，哈哈哈哈
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 要删除的结点不是尾结点
    if(pToBeDeleted->m_pNext != nullptr)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
 
        delete pNext;
        pNext = nullptr;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // 链表中有多个结点，删除尾结点
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;            
        }
 
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

