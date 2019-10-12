/*
 * 题目：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 示例：babad -> bab/aba  cbbd -> bb
 * 思路：
 * 回文串，逆序与原字符串相同。
 */



/*
 * 方法1：中心扩展法。
 * 回文两侧互为镜像，从中心展开，中心可以是一个字母，还可以是两个字母之间。
 * 遍历字符串，依次以每个字母和每两个字母为中心往两遍扩展找回文串。
 * 找出最长回文串的位置。输出即可。
 * 时间复杂度O(n^2)   空间复杂度O(1)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int len; // 记录最长回文串的长度
        int start = 0, end = 0;   // 最长回文子串的起始和结束位置
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);    // 以1个点为中心的回文串长度
            int len2 = expandAroundCenter(s, i, i+1);  // 以2个点为中心的回文串长度
            len = max(len1, len2);
            if (len > end - start + 1) {      // 判断新回文串长度是否比之前回文串长度大
                start = i - (len - 1)/2;  // 更新
                end = i + len/2;
            }
        }
        len = end - start +1;
        cout << len << endl;
        return s.substr(start, len);  // 获取start开始，长度为len的字符串。
    }

    // 从中心开始往两遍扩展，返回回文串的长度
    int expandAroundCenter(string& s, int left, int right) {  // 这里改为传引用，避免copy的事件和内存开销
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

/*
 * 方法2：动态规划
 * 考虑 \textrm{“ababa”}“ababa” 这个示例。如果我们已经知道 \textrm{“bab”}“bab” 是回文，那么很明显，\textrm{“ababa”}“ababa” 一定是回文，因为它的左首字母和右尾字母是相同的。
 * P(i,j) = true,   如果子串Si ... Sj是回文子串
 *          false,  其他情况
 * P(i,j) = (P(i+1, j-1) && Si == Sj)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }

};
