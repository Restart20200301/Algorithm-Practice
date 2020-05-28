namespace Hugo
{
    public class Utils
    {
        public static void Swap<T>(ref T t1, ref T t2)
        {
            T t = t1;
            t1 = t2;
            t2 = t;
        }
    }
}