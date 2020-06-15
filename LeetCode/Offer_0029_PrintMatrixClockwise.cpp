/**
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int k = 0;
        for (int i = 0; i < min((rows + 1) / 2, (cols + 1) / 2); i++) {
            for (int j = i; j < cols - i; j++) {
                ans.push_back(matrix[i][j]);
            }
            for (int j = i + 1; j < rows - i; j++) {
                ans.push_back(matrix[j][cols - i - 1]);
            }
            if (rows / 2 - i > 0) {
                for (int j = cols - i - 2; j >= i; j--) {
                    ans.push_back(matrix[rows - i - 1][j]);
                }
            }
            if (cols / 2 - i > 0) {
                for (int j = rows - i - 2; j > i; j--) {
                    ans.push_back(matrix[j][i]);
                }
            }
        }
        return ans;
    }
};