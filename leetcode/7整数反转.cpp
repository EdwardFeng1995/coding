/*
 * 题目：整数反转
 *       给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 思路：pop = x % 10;
 *       x /= x;
 *       rev = rev * 10 + pop;
 *       判断是否溢出，如果rev > INT_MAX/10, 则，rev = rev * 10 + pop肯定溢出
 *       如果rev = INT_MAX/10, 则如果pop大于最大数字的个位数字就会溢出
 */

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int pop = x % 10;
            x /=10;
            if ((rev > INT_MAX/10) || (rev == INT_MAX/10 && pop > 7))
                return 0;
            if ((rev < INT_MIN/10) || (rev == INT_MIN/10 && pop < -8))
                return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};
