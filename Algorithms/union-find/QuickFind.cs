namespace Algorithms
{
    public class QuickFind : UF
    {
        public QuickFind(int n) : base(n)
        {
        }

        public override void Union(int p, int q)
        {
            int pv = Find(p);
            int qv = Find(q);
            if (pv == qv) return;
            for (int i = 0; i < id.Length; i++)
                if (id[i] == pv)
                    id[i] = qv;
            count--;
        }

        protected override int Find(int p)
        {
            return id[p];
        }
    }
}