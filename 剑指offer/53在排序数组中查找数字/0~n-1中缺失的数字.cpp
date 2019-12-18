// 题目：0～n-1中缺失的数字
// 一个长度为n-1的递增排序序列中有一个数不存在，找出这个数

class Solution {
public:
    int GetMissingNumber(const int* numbers, int length) {
        if (numbers == NULL || length <= 0) return -1;
        int left = 0;
        int right = length-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (numbers[mid] != mid) {
                if (mid == 0 || numbers[mid-1] == mid-1)
                    return mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if (left == length)
            return length;
        return -1;
    }
};
