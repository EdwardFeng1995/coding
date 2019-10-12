/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
//

// 思路1：暴力
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() < 10) {
            return result;
        }
        map<string,int> str_map;
        for (int i = 0; i < s.length()-9; i++) {
            string str_item = "";
            for (int j = i; j -i < 10; j++) {
                str_item += s[j];
            }
            if (str_map.find(str_item) == str_map.end()) {
                str_map[str_item]++;
            } else if (str_map.find(str_item)->second == 1) {
                result.push_back(str_item);
                str_map[str_item]++;
            }
        }
        return result;
    }
};

// 思路2：

int g_hash_map[1048576] = {0}; // 2^20
static const char DNA_CHAR[] = {'A','C','G','T'};

string change_int_to_DNA(int DNA) {
    string str;
    for (int i = 0; i < 10; i++) {
        str += DNA_CHAR[DNA & 3];
        DNA = DNA >> 2;
    }
    return str;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int key = 0;
        if (s.length() < 10) {
            return result;
        }
        for (int i = 0; i < 1048576; i++) {
            g_hash_map[i] = 0;
        }
        
        int char_map[128] = {0};
        char_map['A'] = 0;
        char_map['C'] = 1;
        char_map['G'] = 2;
        char_map['T'] = 3;
        
        for (int i = 9; i >= 0; i--) {
            key = (key << 2) + char_map[s[i]]; 
        }
        g_hash_map[key] = 1;
        for (int i = 10; i < s.length(); i++) {
            key  = key >> 2;
            key = key|(char_map[s[i]] << 18);
            g_hash_map[key]++;
        }
        for (int i = 0; i < 1048576; i++) {
            if (g_hash_map[i] > 1) {
                result.push_back(change_int_to_DNA(i));
            }
        }
        return result;
    }
};

// 思路3：牛人的解法

// @lc code=end
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //对应二进制00, 01, 10, 11.那么10个组合只要20位就够了。
        unordered_map<char, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<string> res;
        bitset<1 << 20> s1, s2; //那么所有组合的值将在0到(1 << 20 - 1)之间
        int val = 0, mask = (1 << 20) - 1; //mask等于二进制的20个1
        //类似与滑动窗口先把前10个字母组合
        for (int i = 0; i < 10; ++i) val = (val << 2) | m[s[i]];
        s1.set(val); //置位
        for (int i = 10; i < s.size(); ++i) {
            val = ((val << 2) & mask) | m[s[i]]; //去掉左移的一个字符再加上一个新字符
            if (s2.test(val)) continue; //出现过两次跳过
            if (s1.test(val)) {
                res.push_back(s.substr(i - 9, 10));
                s2.set(val);
            }
            else s1.set(val);
        }
        return res;
    }
};
