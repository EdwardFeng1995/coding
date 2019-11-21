// 题目：字符串的排列
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if (str.size() == 0) return ans;
        string temp;
        vector<bool> flag(str.size(), false);
        // set<string> s;
        sort(str.begin(), str.end());
        generate(str, 0, flag, temp, ans);
        return ans;
        
    }
    void generate(string& str, int n, vector<bool>& flag, string& temp, vector<string>& ans) {
        if (n == str.size()) {
            /*
            if (s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
            */
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (!flag[i]) {
                // 在进入一个新的分支之前，看一看这个数是不是和之前的数一样，
                // 如果这个数和之前的数一样，并且之前的数还未使用过，
                // 那接下来如果走这个分支，就会使用到之前那个和当前一样的数，就会发生重复，此时分支和之前的分支一模一样。
                if (i >0 && str[i] == str[i-1] && !flag[i-1]) // 去重
                    continue;
                flag[i] = true;
                temp.push_back(str[i]);
                generate(str, n+1, flag, temp, ans);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
};
