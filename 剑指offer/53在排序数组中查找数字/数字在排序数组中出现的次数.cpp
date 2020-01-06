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

// 思路2， 用stl标准库函数
// lower_bound(first, last, value)
// 用于有序数组，如果区间[first, last)存在value，则返回指向第一个元素的迭代器
// 如果区间不存在，便返回“假设这样的元素存在时应该出现的位置”，即返回指向第一个“不小于value”的元素
// 如果value大于区间内任何一个元素，则返回last
//
// upper_bound(first, last, value)
// 返回“在不破坏顺序的情况下，可插入value的最后一个何时位置”
// 所以，如果在区间存在value，则返回最后一个value的下一个位置
class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int target) {
        if(nums.empty()) return 0;
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end()) return 0;
        if (*it1 != target) return 0;
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        return it2 - it1;
    }
};
