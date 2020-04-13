namespace Algorithms
{
    public class WeightedQuickUnionUF : QuickUnion
    {
        private int[] sz;

        public WeightedQuickUnionUF(int n) : base(n)
        {
            sz = new int[n];
            for (int i = 0; i < n; i++) id[i] = 1;
        }

        public override void Union(int p, int q)
        {
            int pRoot = Find(p);
            int qRoot = Find(q);
            if (pRoot == qRoot) return;
            if (sz[pRoot] < sz[qRoot])
            {
                id[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else
            {
                id[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            count--;
        }
    }
}