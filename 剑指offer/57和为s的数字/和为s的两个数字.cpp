// 题目：和为s的数字
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if (array.empty()) return res;
        int min = 0;
        bool firstflag = true;
        auto p1 = array.begin();
        auto p2 = array.end()-1;
        while (p1 < p2) {
            if ((*p1 + *p2) == sum ) {
                if (firstflag) {
                    res.push_back(*p1);
                    res.push_back(*p2);
                    firstflag = false;
                    min = (*p1)*(*p2);
                } else {
                    if ((*p1)*(*p2) < min) {
                        res[0] = *p1;
                        res[1] = *p2;
                        min = (*p1)*(*p2);
                    }
                }
                p1++;
                p2--;
            } else if((*p1 + *p2) > sum) {
                p2--;
            } else {
                p1++;
            }
        }
        return res;
    }
};
