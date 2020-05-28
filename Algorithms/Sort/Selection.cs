using System;
using Hugo;

public class Selection
{
    public static void Sort<T>(T[] a) where T : IComparable<T>
    {
        int n = a.Length;
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[min].CompareTo(a[j]) > 0) min = j;
            }
            Utils.Swap(ref a[i], ref a[min]);
        }
    }
}