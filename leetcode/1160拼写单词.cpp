/*
 * 题目：拼写单词
 * 给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
 * 假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
 * 注意：每次拼写时，chars 中的每个字母都只能用一次。
 * 返回词汇表 words 中你掌握的所有单词的 长度之和。
 *
 * 思路：
 * 首先统计字母表chars中每个字母出现的次数。
 * 然后再针对每个单词的字母出现次数进行统计，
 * 并进行判断，判断单词的每个字母次数是否小于字母表每个字母出现的次数。     
 */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charscount[26] = {0};
        int len = 0;
        for (auto &c : chars) {
            charscount[c - 'a']++;
        }
        
        // 另一种统计方式
        // int s[256] = {0};
		// for(int i = 0;i < chars.length();i++)
		// {
		//  	s[chars[i]]++;
		// } 

        bool isValid = true;
        for (auto &word : words) {
            int wordcharscnt[26] = {0};
            for (auto &w : word) {
                wordcharscnt[w - 'a']++;
                if (wordcharscnt[w - 'a'] > charscount[w - 'a']) {
                    isValid = false;
                    break;
                }
            }
            if(isValid)
                len +=word.size();
            isValid = true;
        }
        return len;
    }
};
