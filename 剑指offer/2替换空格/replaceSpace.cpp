// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
//
// 思路：要问清楚面试官：是否在原字符串修改，若是，字符串后面是否有足够多的空余内存
// 先统计出原字符串的长度和空格的数量，然后计算出，替换空格后字符串的长度，每替换一个
// 空格需要增加两个字符，然后需要两个指针p1，p2，分别指向原字符串的末尾和新字符串的末尾
// 然后向前移动p1，逐个把他指向的字符串复制到p2，直到遇到空格，p2向前移动，依次赋值02%.

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL && length <= 0)
            return;
        
        int length_old = 0; 
        int spacenum = 0;
        int i = 0;
        while(str[i] != '\0') {
            ++length_old;
            if(str[i] == ' ')
                ++spacenum;
            ++i;
        }
        int length_new = length_old + spacenum * 2;
        
        if(length_new > length)
            return;
        
        int p1 = length_old;
        int p2 = length_new;
        while(p1 >= 0 && p2 >p1) {
            if(str[p1] == ' ') {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else {
                str[p2--] = str[p1];
            }
            --p1;
        }
	}
};
