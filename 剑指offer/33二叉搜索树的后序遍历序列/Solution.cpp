// 面试题33：二叉搜索树的后续遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出true,否则输出false。假设输入的数组的任意两个数字都互不相同。
//
// 思路：
// 后续遍历序列的最后一个数字为根节点
// 因为是二叉搜索树，所以，根的左子树都比根小，右子树都比根大
// 正向遍历，直到s[i] > s.back 都是左子树的节点
// 从i到len-1 都是右子树节点，在遍历右子树过程中，如果比根小，则返回false
// 然后递归判断左子树和右子树
class Solution {
public:
    bool VerifySquenceOfBST(vector<int>& sequence) {
        if (sequence.empty()) return false;
        vector<int> left_child;
        vector<int> right_child;
        int i = 0;
        for (; i < sequence.size()-1; i++) {
            if (sequence[i] < sequence.back()) {
                left_child.push_back(sequence[i]);
            } else {
                break;
            }
        }
        int j = i;
        for (; j < sequence.size()-1; j++) {
            if (sequence[j] < sequence.back()) {
                return false;
            } else {
                right_child.push_back(sequence[j]);
            }
        }
        bool left = true;
        if (i>0) 
            left = VerifySquenceOfBST(left_child);
        bool right = true;
        if (i < sequence.size()-1)
            right = VerifySquenceOfBST(right_child);
        return  left && right; 
        
    }
};
