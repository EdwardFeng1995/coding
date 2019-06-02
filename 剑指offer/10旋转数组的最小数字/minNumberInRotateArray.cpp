// 旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
//
// 思路：从头到尾遍历，时间复杂度O(n)，不是面试官想要的
//
// 利用二分查找，时间复杂度O(logn)，是面试官想考察的
// 两个指针index1，index2分别指向数组的第一个和最后一个元素，一般第一个元素大于或者等于最后一个元素。
// 找到中间元素，判断是属于第一个子组还是第二个子组，分别移动index1、index2，当两个差1时，index2所指即为最小数字
// 特殊情况1，前面0个元素搬到后面，旋转数组是原排序数组，第一个元素即为最小，所以indexMid初始化为index1
// 特殊情况2，两个指针指向的数字和中间指针指向的数字一样时，无法判断中间数字属于前面子组还是后面子组，此时不得不顺序遍历
//

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() <= 0)
            return 0;
        int index1 = 0;
        int index2 = rotateArray.size() - 1;
        int indexMid = index1;

        while(rotateArray[index1] >= rotateArray[index2]) {
            if (index2 - 1 == index1) {
                indexMid = index2;
                break;
            }

            int indexMid = (index1 + index2)/2;

            // 如果下标为index1、和index2和indexMid指向的三个数字相等，
            // 则只能顺序查找
            if (rotateArray[index1] == rotateArray[indexMid]
               && rotateArray[index2] == rotateArray[indexMid])
                return MinInOrder(rotateArray, index1, index2);

            if (rotateArray[indexMid] >= rotateArray[index1])
                index1 = indexMid;
            else if (rotateArray[indexMid] <= rotateArray[index2])
                index2 = indexMid;
        }

        return rotateArray[indexMid];
    }

    int MinInOrder(vector<int> rotateArray, int index1, int index2) {
        int result = rotateArray[index1];
        for(int i = index1 + 1; i <= index2; ++i) {
            if (result > rotateArray[i])
                result = rotateArray[i];
        }
        return result;
    }
};
