/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
// 思路：将正方形的边看作是一个桶，然后有四个桶，可以看成是固定个数的固定容量的水桶的接水问题。
// 对于例子[1, 1, 2, 2, 2]，按从大到小排列变成[2, 2, 2, 1, 1]。 正方形的四条边抽象成四个水桶，每个水桶的容量为2，超过容量就会溢出。
// nums[0] = 2，用第一个桶装，刚刚好装满； 
// nums[1] = 2，用第一个桶装，发现2 + 2 = 4 > 2，那么就用第二个桶装，第二个桶也装满；
// nums[2] = 2，用第一个和第二个 桶都装不下，用第三个桶装，那么第三个桶也装满；
// nums[3] = 1，只能用第四个桶装，但没装满；nums[4] = 1，也只能用第四个桶装， 第四个桶也装满了。四个桶都恰好装满表示能构成正方形。
// 69ms
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0;
        int side_length;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        side_length = sum / 4;
        sort(nums.rbegin(), nums.rend());
        int bucket[4] = {0};
        return generate(0, nums, side_length, bucket);
    }
private:
    bool generate(int i, vector<int>& nums, int side_length, int bucket[]) {
        if (i >= nums.size()) {
            return bucket[0] == side_length && bucket[1] == side_length
                && bucket[2] == side_length && bucket[3] == side_length; 
        }
        for (int j = 0; j < 4; j++) {
            if (bucket[j] + nums[i] > side_length) {  // 如果当前桶溢出，则放到下一个桶
                continue;
            }
            bucket[j] += nums[i];
            if (generate(i+1, nums, side_length, bucket)) {  // 递归放后面的火柴
                return true;
            }
            // 说明是false，回溯
            bucket[j] -= nums[i];
        }
        return false;
    }
};


// 大佬写法，速度很快 4ms
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0, side_length, total = 0, index = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        side_length = sum / 4;
        sort(nums.begin(), nums.end());
        if(nums.back()>side_length) return false;
        vector<bool> visit(nums.size(), false);
	    for(int i = 0; i < 4; i++) {
            while(visit[index]) 
                index--;
            if(!DFS(nums, visit, side_length, 0, index)) 
                return false;
        }
        return true;
    }
private:
    bool DFS(vector<int>& nums, vector<bool>& visit, int side_length, int total, int cur) {
        visit[cur] = true;
        total += nums[cur];
        if (total == side_length) return true;
        for (int i = cur - 1; i >= 0; i--) {
            if (!visit[i] && total + nums[i] <= side_length) {
                if (DFS(nums, visit, side_length, total, i))
                    return true;
                visit[i] = false;
            }
        }
        return false;
    }

};
// @lc code=end

