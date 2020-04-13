namespace Algorithms
{
    public abstract class UF
    {
        protected int[] id;
        protected int count;
        
        public UF(int n)
        {
            count = n;
            id = new int[n];
            for (int i = 0; i < n; i++)
                id[i] = i;
        }

        public abstract void Union(int p, int q);

        public bool Connected(int p, int q)
        {
            return Find(p) == Find(q);
        }

        protected abstract int Find(int p);

        public int Count()
        {
            return count;
        }
    }
}