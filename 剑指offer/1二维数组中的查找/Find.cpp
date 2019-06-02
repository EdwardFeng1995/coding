// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
//
// 思路：
// 因为数组是有序的，所以选择右上角（或左下角）的数字与要查找的数字比较。
// 如果是大于，则要查找的数字在左边区域，剔除这一列；
// 如果是小于，则要查找的数字在下方区域，剔除这一行。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(!array.empty()) {
            int row = 0;
            int col = array[row].size() - 1;
            while(row < array.size() && col >= 0) {
                if(array[row][col] == target)
                    return true;
                else if(array[row][col] > target)
                    --col;
                else
                    ++row;
            }
        }
        return false;
    }
};
