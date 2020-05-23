/**
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
 * 整数，判断数组中是否含有该整数。
 */

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        if (array.empty())
            return false;
        int last = array.size() - 1;
        int right = array[0].size() - 1;
        int first = 0;
        while (first <= last && right >= 0) {
            if (array[first][right] == target)
                return true;
            else if (array[first][right] < target)
                first++;
            else
                right--;
        }
        return false;
    }
};