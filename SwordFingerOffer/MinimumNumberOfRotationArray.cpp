/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return -1;
        int first = 0;
        int last = rotateArray.size() - 1;
        while (first < last) {
            int mid = first + ((last - first) >> 1);
            if (rotateArray[mid] > rotateArray[last])
                first = mid + 1;
            else if (rotateArray[mid] == rotateArray[last])
                last--;
            else last = mid;
        }
        return rotateArray[first];
    }
};


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return -1;
        int first = 0;
        int last = rotateArray.size() - 1;
        int mid = 0;
        while (rotateArray[first] >= rotateArray[last]) {
            if (last - first == 1)  return rotateArray[last];
            mid = (first + last) >> 1;
            if (rotateArray[first] == rotateArray[last] && rotateArray[mid] == rotateArray[first]) {
                for (int i = first + 1; i <= last; i++)
                    if (rotateArray[i - 1] < rotateArray[i])
                        return rotateArray[i - 1];
                return rotateArray[first];
            }
            if (rotateArray[first] <= rotateArray[mid])
                first = mid;
            else
                last = mid;
        }
        return rotateArray[mid];
    }
};