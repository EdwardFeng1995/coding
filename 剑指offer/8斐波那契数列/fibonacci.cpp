// 斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0,1};
        if(n < 2)
            return result[n];
         
        int fibn_1 = 1;
        int fibn_2 = 0;
        int fibn = 0;
        for(int i = 2; i <= n; ++i) {
            fibn = fibn_1 + fibn_2;
            fibn_2 = fibn_1;
            fibn_1 = fibn;
        }
        return fibn;
    }
};

// 跳台阶
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
// 本质也是斐波那契数列
//
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else {
            int fibn_1 = 2;
            int fibn_2 = 1;
            int fibn = 0;
            for (int i = 3; i <= number; ++i) {
                fibn = fibn_1 + fibn_2;
                fibn_2 = fibn_1;
                fibn_1 = fibn;
            }
            return fibn;
        }
    }
};


// 变态跳台阶
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。
//
// 方法1，比较蠢
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else {
            int fn = 0;
            int fn_1 = 3;
            for (int i = 3; i <= number; ++i) {
                fn += (fn_1 + 1);
                fn_1 = fn -  1;
            }
            return fn;
        }
    }
};

// 方法2，移位操作
class Solution {
public:
    int jumpFloorII(int number) {
        int a = 1;
        return a<<(number-1);
    }
};

// 方法3
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0)
            return number;
        int total = 1;
        for (int i = 1; i < number; i++) {
            total *= 2;
        }
        return total;
    }
};
