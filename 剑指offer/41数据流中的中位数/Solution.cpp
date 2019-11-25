// 题目：数据流中的中位数
// 如何得到一个数据流中的中位数？
// 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

// 思路：
// 维护一个最大堆和最小堆，最大堆的堆顶＜最小堆的堆顶，并且二者的元素数量差不超过1
class Solution {
public:
    void Insert(int num)
    {
        if (big_heap.empty()) {
            big_heap.push(num);
            return;
        }
        if (big_heap.size() == small_heap.size()) {
            if (num <= big_heap.top()) {
                big_heap.push(num);
            } else {
                small_heap.push(num);
            }
            return;
        }
        if (big_heap.size() == small_heap.size()-1) {
            if (num <= big_heap.top()) {
                big_heap.push(num);
            } else {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
            return;
        }
        if (big_heap.size()-1 == small_heap.size()) {
            if (num <= big_heap.top()) {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            } else {
                small_heap.push(num);
            }
            return;
        }
    }

    double GetMedian()
    { 
        int size = big_heap.size() + small_heap.size();
        if(size == 0) return -1;
        if (size % 2 == 0) {
            return (big_heap.top() + small_heap.top())/2.0;
        }
        else {
            if (big_heap.size() < small_heap.size()) {
                return small_heap.top();
            } else {
                return big_heap.top();
            }
        }
    }
private:
    priority_queue<int> big_heap;
    priority_queue<int, vector<int>, greater<int>> small_heap;
};
