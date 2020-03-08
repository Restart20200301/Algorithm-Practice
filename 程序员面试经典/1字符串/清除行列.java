/**
请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
给定一个N阶方阵int[][](C++中为vector<vector><int>>)mat和矩阵的阶数n，
请返回完成操作后的int[][]方阵(C++中为vector<vector><int>>)，保证n小于
等于300，矩阵中的元素为int范围内。</int></vector></int></vector>
 */

 import java.util.*;

public class Clearer {
    public int[][] clearZero(int[][] mat, int n) {
        // write code here
        boolean[] rows = new boolean[n];
        boolean[] cols = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (mat[i][j] == 0) {
                   rows[i] = true;
                   cols[j] = true;
               }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) {
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }
}