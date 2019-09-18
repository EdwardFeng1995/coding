/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() < 1) {
            return result;;
        }
        string temp("");
        map<int, string> num_str;
        num_str.insert(pair<int,string>(2,"abc"));
        num_str.insert(pair<int,string>(3,"def"));
        num_str.insert(pair<int,string>(4,"ghi"));
        num_str.insert(pair<int,string>(5,"jkl"));
        num_str.insert(pair<int,string>(6,"mno"));
        num_str.insert(pair<int,string>(7,"pqrs"));
        num_str.insert(pair<int,string>(8,"tuv" ));
        num_str.insert(pair<int,string>(9,"wxyz"));
        generate(0, digits, result, temp, num_str);
        return result;
    }
private:
    void generate(int pos, string& digits,
                  vector<string>& result,
                  string& temp,
                  map<int, string>& num_str) {
        if (temp.size() == digits.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = pos; i < digits.size(); i++) {
            for (int j = 0; j < num_str.find(digits[i]-'0')->second.size(); j++) {
                temp.push_back(num_str.find(digits[i]-'0')->second[j]);
                generate(i+1, digits, result, temp, num_str);
                temp.pop_back();
            }
        }
    }
};

