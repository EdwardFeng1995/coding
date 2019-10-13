/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

// 思路1：
class Solution {
public:
    string minWindow(string s, string t) {
        int map_t[128] = {0}; // 记录t字符串中各字符个数
        int map_s[128] = {0}; // 记录s字符串中各字符个数

        vector<int> vec_t; // 记录t字符串中有哪些字符
        for (int i = 0; i < t.length(); i++) {
            map_t[t[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (map_t[i] > 0) {
                vec_t.push_back(i);
            }
        }
        int window_begin = 0; // 最小窗口起始指针
        string result;
        for (int i = 0; i < s.length(); i++) { // i代表了窗口的尾指针
            map_s[s[i]]++;
            while (window_begin < i) {
                char begin_ch = s[window_begin];
                if (map_t[begin_ch] == 0) { // 如果当前头指针所指向的字符没有在字符串t中出现
                    window_begin++;
                } else if (map_s[begin_ch] > map_t[begin_ch]) {
                    map_s[begin_ch]--;
                    window_begin++;
                } else {
                    break;
                }
            }
            cout << window_begin << " " << i << endl;
            if (is_window_ok(map_s, map_t, vec_t)) {
                int new_window_len = i - window_begin + 1;
                if (result == "" || result.length() > new_window_len) {
                    result = s.substr(window_begin, new_window_len);
                }
            }
        }
        return result;
    }

    bool is_window_ok(int map_s[], int map_t[], vector<int> &vec_t) {
        for (int i = 0; i < vec_t.size(); i++) {
            if (map_s[vec_t[i]] < map_t[vec_t[i]]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// 思路2：最后一个例子过不了
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        int t_map[128] = {0};
        vector<string> substr_vec;
        for (int i = 0; i < t.length(); i++) {
            t_map[t[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            string substr = "";
            int flag = 0,count = 0;
            if (t_map[s[i]] > 0) {
                for (int j = i; j < s.length(); j++) {
                    substr += s[j];
                    if (t_map[s[j]] > 0) {
                        t_map[s[j]]--;
                        flag ++;
                    }
                    if (flag == t.length()) {
                        break;
                    }
                }
            }
            for (int l = 0; l < t.length(); l++) {
                if (t_map[t[l]] == 0) {
                    count++;
                }
            }
            if (count == t.length()) {
                substr_vec.push_back(substr);
            }
            for (int k = 0; k < 128; k++) {
                t_map[k] = 0;
            }
            for (int k = 0; k < t.length(); k++) {
                t_map[t[k]]++;
            }
            
        }
        if (substr_vec.size() == 0) {
            return result;
        }
        result = substr_vec[0];
        for (int i = 1; i < substr_vec.size(); i++) {
            if (substr_vec[i].length() < result.length()) {
                result = substr_vec[i];
            }
        }
        return result;
    }
};
