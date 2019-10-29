/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
// 思路1：线段树
void build_segment_tree(vector<int>& value, vector<int>& nums,
                        int pos, int left, int right)
{
    if (left == right) {
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, pos*2+1, left, mid);
    build_segment_tree(value, nums, pos*2+2, mid+1, right);
    value[pos] = value[pos*2+1] + value[pos*2+2];
}

// 线段树求和
int sum_range_segment_tree(vector<int>& value, int pos, int left, int right,
                      int qleft, int qright)
{
    if (qleft > right || qright < left) {
        return 0;
    }
    if (qleft <= left && qright >= right) {
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, pos*2+1, left, mid, qleft, qright) +
           sum_range_segment_tree(value, pos*2+2, mid+1, right, qleft, qright);
}

// 线段树更新
void update_segment_tree(vector<int>& value, int pos, int left, int right,
                         int index, int new_value) {
    if (left == right && left == index) {
        value[pos] = new_value;
        return;
    }
    int mid = (left + right) / 2;
    if (index <= mid) {
        update_segment_tree(value, pos*2+1, left, mid, index, new_value);
    } else {
        update_segment_tree(value, pos*2+2, mid+1, right, index, new_value);
    }
    value[pos] = value[pos*2+1] + value[pos*2+2];
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }
        int n = nums.size() * 4;  // 一般线段树数组大小是原数组大小长度的4倍
        for (int i = 0; i < n; i++) {
            _nums.push_back(0);
        }
        build_segment_tree(_nums, nums, 0, 0, nums.size()-1);
        _right_end = nums.size() - 1;
    }
    
    void update(int i, int val) {
        update_segment_tree(_nums, 0, 0, _right_end, i, val);
    }
    
    int sumRange(int i, int j) {
        return sum_range_segment_tree(_nums, 0, 0, _right_end, i, j);
    }
private:
    vector<int> _nums;
    int _right_end;
};

// 思路2：普通做法
class NumArray {
public:
    NumArray(vector<int>& nums) {
        _nums = {nums.begin(), nums.end()};
    }
    
    void update(int i, int val) {
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int p = i; p <= j; p++) {
            sum += _nums[p];
        }
        return sum;
    }
private:
    vector<int> _nums;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

