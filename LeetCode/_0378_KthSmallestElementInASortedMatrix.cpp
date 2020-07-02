/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
 

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int first = matrix[0][0];
        int last = matrix[n - 1][n - 1];
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (check(matrix, mid, k, n))
                last = mid;
            else
                first = mid + 1;
        }
        return first;
    }
private:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int row = n - 1;
        int col = 0;
        int count = 0;
        while (col < n && row >= 0) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                ++col;
            } else
                --row;
        }
        return count >= k;
    }
};