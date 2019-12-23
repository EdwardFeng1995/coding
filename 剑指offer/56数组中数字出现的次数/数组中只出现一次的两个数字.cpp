// 题目：
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
// 思路：
// 设两个数字为num1 和 num2
// 将所有数字异或一遍，得到num1 和 num2的异或结果，xor
// 取xor中为1的位，例如最后一个为1的位，为1说明num1和num2在该位不同
// 以该位是否为1进行分组，相同的数字肯定会分到一组，而num1和num2也会分到不同的组
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int x = 0;
        for (int i = 0; i < data.size(); i++) {
            x ^= data[i];
        }
        int benchmark = x & (~x + 1);
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & benchmark) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }
    }
};
