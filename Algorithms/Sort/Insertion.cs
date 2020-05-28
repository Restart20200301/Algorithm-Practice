using System;
using Hugo;

public class Insertion
{
    public static void Sort<T>(T[] a) where T : IComparable<T>
    {
        int n = a.Length;
        for (int i = 1; i < n; i++)
        {
            int j = i;
            while (j > 0 && a[j].CompareTo(a[j - 1]) < 0)
            {
                Utils.Swap(ref a[j], ref a[j - 1]);
                j--;
            }
        }
    }
}