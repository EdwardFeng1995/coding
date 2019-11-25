// 题目：最小的k个数
// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

// 思路1：先排序，然后取出前k个数
// 时间复杂度：O(nlogn)


// 思路2：基于Pattition函数，但是会更改输入数组
// 时间复杂度：O(n)
class Solution {
public:
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if (input.empty()) return ans;
        if (k > input.size() || k <= 0) return ans;
        int n = input.size();
        int start = 0;
        int end = n-1;
        int index = Partition(input, start, end);
        while (index != k-1) {
            if (index > k-1) {
                end = index-1;
                index = Partition(input, start, end);
            } else {
                start = index + 1;
                index = Partition(input, start, end);
            }
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(input[i]);
        }
        return ans;
    }
private:
     
    int Partition(vector<int>& input, int low, int high) {
        if (low >= high)
            return low;
        int pivotkey;
        pivotkey = input[low];
        int temp = pivotkey;
        while (low < high) {
            while (low < high && input[high] >= pivotkey)
                high--;
            input[low] = input[high];
            while (low < high && input[low] <= pivotkey)
                low++;
            input[high] = input[low];
        }
        input[low] = temp;
        return low;
    }
};

// 思路3：利用最大堆，先push k个元素，然后从k+1开始与堆顶比较，如果比对顶小，就push，pop
// 时间复杂度：O(nlogk)，适合海量处理海量数据
class Solution {
public:
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if (input.empty()) return ans;
        if (k > input.size() || k <= 0) return ans;
        priority_queue<int, vector<int>, less<int>> Q;
        for (int i = 0; i < input.size(); i++) {
            if (Q.size() < k) {
                Q.push(input[i]);
            } else if (input[i] < Q.top()) {
                Q.pop();
                Q.push(input[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(Q.top());
            Q.pop();
        }
        return ans;
    }
};
