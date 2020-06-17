/**
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自 百度百科 - 皇后 ）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(ans, v, 0, n);
        return ans;
    }
private:
    void solve(vector<vector<string>>& ans, vector<string>& step, int pos, int n) {
        if (pos == n) {
            ans.push_back(step);
            return;
        }
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int i = 0; i < pos; i++) {
                if (step[i][j] == 'Q') { flag = false; break; }
                int dis = pos - i;
                if (j - dis >= 0 && step[i][j - dis] == 'Q') { flag = false; break; }
                if (j + dis < n && step[i][j + dis] == 'Q') { flag = false; break; }
            }
            if (!flag) continue;
            string str(n, '.');
            str[j] = 'Q';
            step.push_back(str);
            solve(ans, step, pos + 1, n);
            step.pop_back();
        }
    }
};