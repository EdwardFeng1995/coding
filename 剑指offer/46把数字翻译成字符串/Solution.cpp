// 题目：把数字翻译成字符串
// 给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成“a”，1翻译成“b”...25翻译成“z”
// 一个数字可能有多个翻译
// 例如，12258有5中不同的翻译，分别是“bccfi”、“bwfi”、“bczi”、“mcfi”和“mzi”
// 请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法
#include <iostream>
#include <vector>
using namespace std;

// 动态规划
// f(i)表示从第i位数字开始的不同的翻译的数目
// f(i)=f(i+1)+g(i,i+1)*f(i+2)
// g(i,i+1)表示第i位和第i+1位两位数字拼接起来的数字在10~25范围内时，值为1，否则为0

int GetTranslationCount(int number) 
{
    if (number < 0) return 0;
    string nstring = to_string(number);
    vector<int> dp(nstring.size(), 0);
    dp.back() = 1;
    
    for (int i = nstring.length()-2; i >= 0; i--) {
        int g = (nstring[i]-'0') > 0 && (nstring[i]-'0')*10+(nstring[i+1]-'0') <= 25 ? 1 : 0;
        if (i+2 < nstring.length())
            dp[i] = dp[i+1] +g*dp[i+2];
        else
            dp[i] = dp[i+1] + g;
    }
    return dp[0];
}

/*
// 递归思路，但是有很多重复

void helper(const string& nstring, int i, int& count) 
{
    if (i == nstring.size()) {
        count ++;
        return;
    }
    if (nstring[i]-'0' <= 25) {
        helper(nstring, i+1, count);
    }
    if ( (nstring[i]-'0')*10+(nstring[i+1]-'0') <= 25 && (nstring[i]-'0') > 0 && i+1 < nstring.size()) {
        helper(nstring, i+2, count);
    }
}

int GetTranslationCount(int number)
{
    if (number < 0) return 0;
    string nstring = to_string(number);
    int count = 0;
    helper(nstring, 0, count);
    return count;
}
*/
// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{
    if(GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

