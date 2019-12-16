// 题目：数字在排序数组中出现的次数
// 统计一个数字在排序数组中出现的次数。
// 思路：二分查找，找第一个的位置，右侧逼近
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() < 1) return 0;
        int n = data.size();
        int first, last, l = 0, r = n-1, count = 0;
        while (l < r) {
            int mid = (l + r)/2;
            if (data[mid] >= k) r = mid;
            else l = mid+1;
        }
        if (data[l] != k) return 0;
        first = l;
        r = n; // 找上边界返回的是最后一个位置的下一个位置，所以r也要是整个数组最后一个位置的下一位置
        while (l < r) {
            int mid = (l + r)/2;
            if (data[mid] <= k) l = mid+1;
            else r = mid;
        }
        last = l-1;
        return last - first + 1;
    }
};
