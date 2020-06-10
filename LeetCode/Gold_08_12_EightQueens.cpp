/**
设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。

注意：本题相对原题做了扩展

示例:

 输入：4
 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/eight-queens-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        char** data = new char*[n];
        for (int i = 0; i < n; i++)
            data[i] = new char[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                data[i][j] = '.';
        
        vector<vector<string>> res;
        back(data, 0, res, n);
        for (int i = 0; i < n; i++)
            delete[] data[i];
        delete[] data; 
        return res;
    }

    void back(char** data, int curRow, vector<vector<string>>& res, int n) {
        if (curRow == n) {
            vector<string> v;
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < n; j++) {
                    s += data[i][j];
                }
                v.push_back(s);
            }
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            bool isOk = true;
            for (int j = 0; j < curRow; j++) {
                // 同一列
                if (data[j][i] == 'Q') { isOk = false; break; }
                // 对角线
                if (i - curRow + j >= 0 && data[j][i - (curRow - j)] == 'Q') { isOk = false; break; }
                if (i + curRow - j < n && data[j][i + (curRow - j)] == 'Q') { isOk = false; break; }
            }
            if (!isOk) continue;
            data[curRow][i] = 'Q';
            back(data, curRow + 1, res, n);
            data[curRow][i] = '.';
        } 
    }
};