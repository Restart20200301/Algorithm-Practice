using System;
using Hugo;

public class Shuffle
{
    public static void Sort<T>(T[] a)
    {
        int n = a.Length;
        var random = new Random();
        for (int i = 1; i < n; i++)
        {
            var pos = random.Next(0, i + 1);
            Utils.Swap(ref a[i], ref a[pos]);
        }
    }
}