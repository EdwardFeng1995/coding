// 题目：把数组排成最小的数
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


// 思路：
// 自定义一个排序规则，比较s1+s2 和 s2+s1
// 然后排序，拼接即可
// 如果数组中全是0，返回"0"即可

class Solution {
public:
    static bool cmp(const int& x, const int& y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        return (s1 + s2) < (s2 + s1);
    }
    string PrintMinNumber(vector<int> numbers) {
        string ans = "";
        if (numbers.empty()) return ans;
        if (all_of(numbers.begin(), numbers.end(), [](int x) { return x == 0; })) {
            return string("0");
        }
        sort(numbers.begin(), numbers.end(), cmp);
        for (auto &i:numbers) {
            ans += to_string(i);
        }
        return ans;
    }
};
