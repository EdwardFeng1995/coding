// 题目：第一个只出现一次的字符
// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.length() < 1) return -1;
        int hash[256];
        for (int i = 0; i < 256; i++)
            hash[i] = 0;
        for (int i = 0; i < str.length(); i++)
            hash[str[i]]++;
        for (int i = 0; i < str.length(); i++) {
            if (hash[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
