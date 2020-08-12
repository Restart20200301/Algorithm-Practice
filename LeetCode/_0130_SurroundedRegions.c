/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
void dfs(char** board, int rows, int cols, int x, int y) {
    if (x < 0 || y < 0 || x >= rows || y >= cols || board[x][y] != 'O') return;
    board[x][y] = 'T';
    dfs(board, rows, cols, x, y + 1);
    dfs(board, rows, cols, x + 1, y);
    dfs(board, rows, cols, x - 1, y);
    dfs(board, rows, cols, x, y - 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0 || *boardColSize == 0) return;
    for (int i = 0; i < *boardColSize; i++) {
        dfs(board, boardSize, *boardColSize, 0, i);
        dfs(board, boardSize, *boardColSize, boardSize - 1, i);
    }

    for (int i = 0; i < boardSize; i++) {
        dfs(board, boardSize, *boardColSize, i, 0);
        dfs(board, boardSize, *boardColSize, i, *boardColSize - 1);
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'T')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}