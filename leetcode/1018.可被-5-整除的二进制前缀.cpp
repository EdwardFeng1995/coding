/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        long long temp = 0;
        for (int i = 0; i < A.size(); i++) {
            temp = temp << 1;
            temp += A[i];
            temp = temp%5;
            /*
            for (int j = 0; j <= i; j++) {
                temp = temp << 1;
                //cout << temp << " ";
                temp += A[j];
                temp = temp%5;
                //cout << temp << endl;
            }
            */
            // temp >> 1;
            // cout << temp << endl;
            if (temp == 0) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};
// @lc code=end

