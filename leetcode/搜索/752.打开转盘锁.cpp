/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start

// 思路：与126,127类似，单端BFS，双端BFS
// 双端：
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set_dea = {deadends.begin(), deadends.end()};
        if (set_dea.count("0000") || set_dea.count(target)) {
            return -1;
        }
        queue<string> q1;
        queue<string> q2;
        unordered_set<string> p1{"0000"};
        unordered_set<string> p2{target};
        q1.push("0000");
        q2.push(target);
        const int l = 4;
        int count = 0;
        while (!q1.empty() && !q2.empty()) {
            count++;
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(p1, p2);
            }
            for (int size = q1.size(); size > 0; size--) {
                string number = q1.front();
                // cout << number << " ";
                q1.pop();
                for (int i = 0; i < l; i++) {
                    string temp = number;
                    /*
                    for (int j = -1; j <= 1; j += 2) {
                        number = temp;
                        number[i] = (number[i] - '0' + j + 10) % 10 + '0';
                        if (number == target) return count;
                        if (set_dea.count(number) || p.count(number)) continue; 
                        q.push(number);
                        p.insert(number);
                    }
                    */
                    for (int c = 0; c < 2; c++) {
                        number = temp;          
                        if (c == 0) {
                            if (number[i] +1 > '9') {
                                number[i] = '0';
                            } else {
                                number[i] = number[i] + 1;
                            }
                        }
                        if (c == 1) {
                            if (number[i] -1 < '0') {
                                number[i] = '9';
                            } else {
                                number[i] = number[i] - 1;
                            }
                        }
                        if (p2.count(number)) {
                            return count;
                        }
                        if (set_dea.count(number) || p1.count(number)) {
                            continue;
                        }
                        q1.push(number);
                        p1.insert(number);
                        
                    }
                    number = temp;
                }
            }
        }

        return -1;
    }
};

// 单端：
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set_dea = {deadends.begin(), deadends.end()};
        if (set_dea.count("0000") || set_dea.count(target)) {
            return -1;
        }
        queue<string> q;
        unordered_set<string> p{"0000"};
        q.push("0000");
        const int l = 4;
        int count = 0;
        while (!q.empty()) {
            count++;
            //cout << count << endl;
            for (int size = q.size(); size > 0; size--) {
                string number = q.front();
                //cout << number << " ";
                q.pop();
                for (int i = 0; i < l; i++) {
                    string temp = number;
                    for (int c = 0; c < 2; c++) {
                        number = temp;
                        if (c == 0) {
                            if (number[i] +1 > '9') {
                                number[i] = '0';
                            } else {
                                number[i] = number[i] + 1;
                            }
                        }
                        if (c == 1) {
                            if (number[i] -1 < '0') {
                                number[i] = '9';
                            } else {
                                number[i] = number[i] - 1;
                            }
                        }
                        if (number == target) {
                            return count;
                        }
                        if (set_dea.count(number) || p.count(number)) {
                            continue;
                        }
                        q.push(number);
                        p.insert(number);
                    }
                    number = temp;
                }
            }
            //cout << endl;
        }

        return -1;
    }
};
// @lc code=end

