// 题目：1～n整数中1出现的次数
// 输入一个整数n，求1～n这n个整数的十进制表示中1出现的次。
// 例如，输入12,1~12这些整数中包含1的数字有1 10 11 12一共5次


// 思路：找规律
// 观察到每10个数，个位上的’1’ 就会出现1次。同样的，每100个数，十位上的 ’1’ 就会出现10次。
// 这个规律可以用 (n/(i*10))*i公式来表示。
//
// 同时，如果10位上的数是1，最后1的数量要加上x+1，其中x是个位上的数值。
// 如果10位上的数大于1，那么10位上为1的所有的数都是符合要求的，这时候最后1的数量要加10
// 这个规律可以用公式min(max(n%(i*10)-i+1, 0), i)来表示

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            count += (n/divider)*i + min(max(n%divider-i+1, 0LL), i);
        }
        return count;
    }
};

