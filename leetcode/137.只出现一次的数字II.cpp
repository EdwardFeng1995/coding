// 题目：只出现一次的数字ii
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bitmask = 1 << i;
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & bitmask) {
                    cnt++;
                }
            }
            if (cnt % 3) {
                res |= bitmask;
            }
        }
        return res;
    }
};
