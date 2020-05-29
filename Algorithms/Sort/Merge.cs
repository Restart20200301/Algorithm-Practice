using System;
using System.Diagnostics;

public class Merge
{
    public static void Sort<T>(T[] a) where T: IComparable<T>
    {
        int n = a.Length;
        T[] copy = new T[n];
        Sort(a, copy, 0, n - 1);
    }

    private static void Sort<T>(T[] a, T[] copy, int low, int high) where T : IComparable<T>
    {
        if (low >= high) return;
        int mid = low + ((high - low) >> 1);
        Sort(a, copy, low, mid);
        Sort(a, copy, mid + 1, high);
        MergeArray(a, copy, low, mid, high);
    }

    private static void MergeArray<T>(T[] a, T[] copy, int low, int mid, int high) where T: IComparable<T>
    {
        Debug.Assert(IsSort(a, low, mid));
        Debug.Assert(IsSort(a, mid + 1, high));
        for (int i = low; i <= high; i++)
            copy[i] = a[i];

        int j = low, k = mid + 1;
        for (int i = low; i <= high; i++)
        {
            if (j > mid) a[i] = copy[k++];
            else if (k > high) a[i] = copy[j++];
            else if (copy[j].CompareTo(copy[k]) < 0) a[i] = copy[j++];
            else a[i] = copy[k++];
        }
        Debug.Assert(IsSort(a, low, high));
    }

    public static bool IsSort<T>(T[] a, int low, int high) where T : IComparable<T>
    {
        for (int i = low + 1; i <= high; i++)
        {
            if (a[i].CompareTo(a[i - 1]) < 0)
                return false;
        }
        return true;
    }
}