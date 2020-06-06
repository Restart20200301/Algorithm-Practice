using System;
using Hugo;

public class Heap
{
    public static void Sort<T>(T[] a) where T: IComparable<T>
    {
        int n = a.Length;
        for (int k = (n - 1) / 2; k >= 0; k--)
            Sink(a, k, n - 1);
        while (n > 1)
        {
            Utils.Swap(ref a[n-- - 1], ref a[0]);
            Sink(a, 0, n - 1);
        }
    }

    private static void Sink<T>(T[] a, int first, int last) where T: IComparable<T>
    {
        while (first * 2 + 1 <= last)
        {
            int child = first * 2 + 1;
            if (child < last && a[child].CompareTo(a[child + 1]) < 0) child++;
            if (a[first].CompareTo(a[child]) > 0) break;
            Utils.Swap(ref a[first], ref a[child]);
            first = child;
        }
    }
}