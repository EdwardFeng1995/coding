/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 * 思路：
 * 1. 该数据结构可以设计为数组
 *    在add时，将数组排序，复杂度O(n)，find复杂度O(1)
 *    在find时将数组排序，复杂度O(n)，add复杂度O(1)
 *
 * 2. 建立一个最大堆和一个最小堆，最大堆堆顶小于最小堆堆顶，且两个堆的大小差不超过1
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (big_heap.empty()) {
            big_heap.push(num);
            return;
        }

        if (big_heap.size() == small_heap.size()) {
            if (num > big_heap.top()) {
                small_heap.push(num);
            } else {
                big_heap.push(num);
            }
        } else if (big_heap.size()-1 == small_heap.size()) {
            if (num > big_heap.top()) {
                small_heap.push(num);
            } else {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        } else if (big_heap.size() == small_heap.size()-1) {
            if (num < small_heap.top()) {
                big_heap.push(num);
            } else {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (small_heap.size() == big_heap.size()) {
            return (small_heap.top() + big_heap.top())/2.0;
        } else if (small_heap.size() == big_heap.size()-1) {
            return big_heap.top();
        } else if (big_heap.size() == small_heap.size()-1) {
            return small_heap.top();
        } else {
            return 0;
        }
        
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap;
    std::priority_queue<int> big_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

