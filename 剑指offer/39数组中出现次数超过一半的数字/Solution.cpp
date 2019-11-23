// 题目：数组中出现次数超过一半的数字
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
// 如果不存在则输出0。

// 思路1：哈希表，map统计次数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if (size == 0) return 0;
        if (size == 1) return numbers[0];
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++) {
            m[numbers[i]]++;
            if (m[numbers[i]] > size/2) {
                return numbers[i];
            }
        }
        return 0;
    }
};

// 思路2
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if (size == 0) return 0;
        if (size == 1) return numbers[0];
        int result = numbers[0];
        int times = 1;
        for (int i = 0; i < size; i++) {
            if (times == 0) {
                result = numbers[i];
                times = 1;
            } else if (result == numbers[i]) {
                times++;
            } else {
                times--;
            }
        }
        times = 0;
        for (int i = 0; i < size; i++) {
            if (numbers[i] == result) {
                times++;
            }
        }
        if (times > size/2) return result;
        return 0;
    }
};

// 思路3：基于partition函数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len==0)
            return 0;
        if(len==1)
            return numbers[0];
        int begin = 0;
        int end = len -1;
        int index = Partition(numbers, begin, end);
        // 寻找中位数
        while (index!=numbers.size()/2){
            if (index < len/2){
                begin = index +1;
                index = Partition(numbers,begin+1,end);
            }
            else{
                end = index -1;
                index = Partition(numbers,begin,end);
            }
        }

        // 遍历一遍统计该元素
        int count = 0;
        int key = numbers[index];
        for (int i = 0; i < len; ++i) {
            if(numbers[i] == key)
                ++ count;
        }
        if(count>len/2)
            return key;
        return 0;
    }

    int Partition(vector<int> &numbers, int begin, int end){
        if(begin >= end)
            return begin;

        int key = numbers[begin];   // 首元素作为基准值

        while (begin<end){
            while (begin<end && numbers[end] >= key)
                -- end;
            numbers[begin] = numbers[end];
            while (begin<end && numbers[begin] <= key)
                ++ begin;
            numbers[end] = numbers[begin];
        }
        numbers[begin] = key;
        return begin;
    }
};

