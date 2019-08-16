/*
 * 题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入："abcabcbb" 输出3
 *       "bbbb"     输出1
 *       "pwwke"    输出3
 *       
 * 思路：设置两个索引，i为子串的起始，j为子串的结束。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){  // j代表子串的结尾
            for(k = i;k<j;k++)  
                if(s[k]==s[j]){ // i代表子串的开始，从i开始判断子串中是否有与结尾相同的字符
                                // 若有，则子串的起始位置变为相同字符位置+1
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};
