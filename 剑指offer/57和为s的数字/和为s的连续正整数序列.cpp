// 题目：和为S的连续正整数序列
// 输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如，输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以打印出3个连续序列1~5、4~6、7~8
//

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum < 3) return res;
        int small = 1;
        int big = 2;
        int middle = (1+sum)/2;
        int cursum = small + big;
        while (small < middle) {
            if (cursum == sum) {
                res.push_back(generate(small, big));
            }
            while (cursum > sum && small < middle) {
                cursum -= small;
                small++;
                if (cursum == sum) {
                    res.push_back(generate(small, big));
                }
            }
            big++;
            cursum += big;
        }
        return res;

    }

    vector<int> generate(int small, int big) {
        vector<int> temp;
        while (small <= big) {
            temp.push_back(small);
            small++;
        }
        return temp;
    }
};
