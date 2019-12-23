// 题目：
// 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

class Solution {
public:
    vector<int> singleNumber(vector<int>& data) {
        vector<int> res;
        int x = 0;
        for (int i = 0; i < data.size(); i++) {
            x ^= data[i];
        }
        int benchmark = x & (~x + 1);
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & benchmark) {
                num1 ^= data[i];
            } else {
                num2 ^= data[i];
            }
        }
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};
