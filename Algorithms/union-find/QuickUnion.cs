namespace Algorithms
{
    public class QuickUnion : UF
    {
        public QuickUnion(int n) : base(n)
        {
        }

        public override void Union(int p, int q)
        {
            int pRoot = Find(p);
            int qRoot = Find(q);
            if (pRoot == qRoot) return;
            id[pRoot] = qRoot;
            count--;
        }

        protected override int Find(int p)
        {
            while (p != id[p])
            {
                id[p] = id[id[p]]; // 压缩路径，使树高度再次降低
                p = id[p];
            }
            return p;
        }
    }
}