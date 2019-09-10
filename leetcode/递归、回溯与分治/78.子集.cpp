/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * 思路：
 * 1.递归+回溯：
 * 对于每个元素，都有放入或不放入集合中两个选择
 * 选择放入该元素，递归的进行后续元素的选择，完成放入钙元素后续所有元素的试探
 * 之后将其拿出，即再进行一次选择不放入该元素，递归的进行后续元素的选择，完成
 * 不放入该元素后续所有元素的试探
 *
 * 2.位运算
 * 本题的本质是数组中元素取与不取的组合，一共有2^n种可能
 * 例如,[1,2,3]，把它想象成三个bit位1 1 1，那么从0 0 0到1 1 18个数，
 * 就构成了所有子集的选取情况，然后使用123对应的三个整除与集合对应的整数做&运算，
 * 当为真时，将该元素push进入集合
 *
 * 3.遍历，每遇到一个数，就给已有的所有子集都加上该数组成新的子集
 */

// 思路1：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item);
        generate(0, nums, item, result);
        return result;
    }
private:
    void generate(int i, 
             vector<int>& nums, 
             vector<int>& item,
             vector<vector<int>>& result) {
        
        if (i == nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }
};


// 思路2：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int all_set_nums = 1 << nums.size();   // 所有子集的数目
                                               // 1<<n = 2^n
        vector<vector<int>> result;
        for (int i = 0; i < all_set_nums; i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

// 思路3：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for (auto i:nums) { // 对于每一个数
            int size = result.size();
            // 给已有的所有子集都加上该数，生成新的子集
            for (int j = 0; j < size; j++) {
                vector<int> temp = result[j];
                temp.push_back(i);
                result.push_back(temp);
            }
        }
        return result;
    }
};
