/*
 * 题目：反转字符串
 *       编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 *       不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *       你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 *
 * 思路：1、双指针start，end分别指向头和尾，交换，然后start++，end--直到start>=end
 *       2、交换的位置和+1为size，交换s[i]和s[n-1-i]
 *       3、递归
 *       4、按位^(异或)运算
 *          A=A^B
 *          B=A^B
 *          A=A^B  三条语句可实现交换
 */

// 方法1
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        char tmp = 0;
        while (start < end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};

// 方法2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=size(s);
        for(int i=0;i<n/2;i++)
        {
            char temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
        }
    }
};

// 方法3
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        recursive(s, 0, s.size()-1);
    }
    
    
    void recursive(vector<char> &s, int start, int end){
        if (start > end)
            return;
        recursive(s, start+1, end-1);
        swap(s[start], s[end]);
    }
};

// 方法4
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            s[i] ^=s[n-1-i];
            s[n-1-i] ^=s[i];
            s[i] ^=s[n-1-i];
        }
    }
};
