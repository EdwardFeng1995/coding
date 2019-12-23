// 题目：数组中唯一只出现一次的数字
// 在一个数组中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

// 思路：
// 把数组中所有数字的二进制表示的每一位都加起来。
// 如果某一位的和能被3整除，那么那个只出现一次的数字二进制表示中对应的哪一位是0；
// 否则就是1
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
