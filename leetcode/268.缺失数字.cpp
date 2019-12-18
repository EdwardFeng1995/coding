// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return -1;
        int n = nums.size();
        int sum = n*(n+1)/2;
        for (auto i:nums) {
            sum -= i;
        }
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return -1;
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
