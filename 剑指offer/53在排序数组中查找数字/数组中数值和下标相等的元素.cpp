// 题目：数组中数值和下标相等的元素
// 假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
// 找出数组中任意一个数值等于其下标的元素。

class Solution {
public:
    int GetNumberSameAsIndex(const int* numbers, int length) {
        if (numbers == NULL || length <= 0) return -1;
        int left = 0;
        int right = length-1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (numbers[mid] == mid)
                return mid;
            if (numbers[mid] > mid)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
};
