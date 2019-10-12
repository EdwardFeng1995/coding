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

// 思路2：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, max = 0, begin = 0;
        int char_map[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (char_map[s[i]] != 0) {
                begin = begin + 1;
                i = begin;
                for (int j = 0; j < 128; j++) {
                    char_map[j] = 0;
                }
                if (len > max) {
                    max = len;
                }
                len = 0;
                //continue;
            }
            char_map[s[i]] = 1;
            len++;
        }
        if (len > max) {
            max = len;
        }
        return max;
    }
};

// 思路3：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int res = 0;
        string word = "";
        int char_map[128] = {0};
        for (int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
            if (char_map[s[i]] == 1) {
                word += s[i];
                if (res < word.length()) {
                    res = word.length();
                }
            } else {
                while (begin < i && char_map[s[i]] > 1) {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";
                for (int j = begin; j <= i; j++) {
                    word += s[j];
                }
            }
        }
        return res;
    }
};
