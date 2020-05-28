using System;
using Hugo;

public class Shell
{
    public static void Sort<T>(T[] a) where T : IComparable<T>
    {
        int n = a.Length;
        int h = 1;
        while (h < n / 3) h = 3 * h + 1;
        for (; h >= 1; h /= 3)
        {
            for (int i = h; i < n; i++)
            {
                for (int j = i; j >= h && a[j].CompareTo(a[j - h]) < 0; j -= h)
                {
                    Utils.Swap(ref a[j], ref a[j - h]);
                }
            }
        }
    }
}