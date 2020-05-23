/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 
 * 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> vec;
        if (matrix.empty())
            return vec;
        print(matrix, vec, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
        return vec;
    }
    inline void print(vector<vector<int>>& matrix, vector<int>& vec, int start, int last, int begin, int end) {
        int cnt = min((last + 2) >> 1, (end + 2) >> 1 );
        while (cnt--) {
            for (int i = start; i <= last; i++)
                vec.push_back(matrix[begin][i]);
            for (int i = begin + 1; i <= end; i++)
                vec.push_back(matrix[i][last]);
            if (end > begin)
                for (int i = last - 1; i >= start; i--)
                    vec.push_back(matrix[end][i]);
            if (start < last)
                for (int i = end - 1; i >= begin + 1; i--)
                    vec.push_back(matrix[i][start]);
            start++;
            last--;
            begin++;
            end--;
        }
    }
};