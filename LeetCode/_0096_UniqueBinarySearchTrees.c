/**
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

 
// n G(n) 需要求的结果
// F(i)  以i为底的二叉树
// F(i) = G(i - 1)*G(i + 1)
// G(n) = sum(i = 1...n F(i)) = sum(i = 1..n G(i - 1)*G(n - i))
int numTrees(int n) {
    if (n <= 0) return 1;
    int* G = malloc(sizeof(int) * (n + 1));
    memset(G, 0, sizeof(int) * (n + 1));
    G[0] = 1; G[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    int res = G[n];
    free(G);
    return res;
}