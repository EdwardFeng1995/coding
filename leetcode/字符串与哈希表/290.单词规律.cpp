/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;
        char used[128] = {0};
        string word;
        int pos = 0;
        str.push_back(' ');
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (pos == pattern.length()) { // 单词个数与pattern字符个数不同，不匹配
                    return false;      
                }
                if (word_map.find(word) == word_map.end()) { // 当前单词还没有与patter字符的映射，
                    if (used[pattern[pos]]) { // 当前patter字符已经映射过，说明不匹配。                    
                        return false;  
                    } else {   // 否则，建立映射
                        word_map.insert(pair<string,char>(word,pattern[pos]));
                        used[pattern[pos]] = 1;
                    } 
                } else {
                    if (word_map.find(word)->second != pattern[pos]) {
                        return false;
                    }
                }
                word = "";
                pos++; 
            } else {
                word += str[i];
            }
        }
        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};
// @lc code=end

