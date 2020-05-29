using System;
using Hugo;

public class Quick
{
     public static void Sort<T>(T[] a) where T : IComparable<T>
     {
          Sort(a, 0, a.Length - 1);
     }

     private static void Sort<T>(T[] a, int low, int high) where T : IComparable<T>
     {
          if (low >= high) return;
          int mid = Partition(a, low, high);
          Sort(a, low, mid - 1);
          Sort(a, mid + 1, high);
     }

     private static int Partition<T>(T[] a, int low, int high) where T : IComparable<T>
     {
          while (low < high)
          {
               while (a[low].CompareTo(a[high]) < 0) high--;
               if (low < high) Utils.Swap(ref a[low++], ref a[high]);
               while (a[low].CompareTo(a[high]) < 0) low++;
               if (low < high) Utils.Swap(ref a[low], ref a[high--]);
          }

          return low;
     }
}