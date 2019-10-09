/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int n=nums.size(),l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>=target) r=m;
            else l=m+1;
        }
        if(nums[l]!=target) return res;
        res[0]=l;
        r=n;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<=target) l=m+1;
            else r=m;
        }
        res[1]=l-1;
        return res;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> re;
        if (nums.empty()) {
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }
        int begin = 0, end = nums.size()-1;
        int mid = (begin + end)/2;
        while (begin <= end) {
            if (target == nums[mid]) {
                int a = begin;
                int b = 0;
                int mid2 = mid;
                begin = mid + 1;
                if (begin > end) {
                    b = begin -1;
                }
                while (begin <= end) {
                    mid = (begin + end)/2;
                    if (target == nums[mid]) {
                        begin = mid +1;
                    } else {
                        end = mid - 1;
                    }
                    if (begin > end) {
                        b = begin - 1;
                    }
                }
                end = mid2 - 1;
                
                while (a <= end) {
                    mid2 = (a + end)/2;
                    if (target == nums[mid2]) {
                        end = mid2 -1;
                    } else {
                        a = mid2 + 1;
                    }
                    if (a > end) {
                        break;
                    }   
                }
                re.push_back(a);
                re.push_back(b);
                break;
            } else if (target > nums[mid]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
            if (begin > end) {
                re.push_back(-1);
                re.push_back(-1);
            }
            mid = (begin + end)/2;
        }
        return re;
    }
};
// @lc code=end

