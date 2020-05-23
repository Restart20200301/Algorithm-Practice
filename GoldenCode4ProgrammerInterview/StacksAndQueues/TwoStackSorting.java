/**
 * Two stack sorting
 * 请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
 * 给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到最后一个元素。

 * 测试样例：
 * [1,2,3,4,5]
 * 返回：[5,4,3,2,1]
 */

import java.util.*;

public class TwoStacks {
    public ArrayList<Integer> twoStacksSort(int[] numbers) {
        // write code here
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        
        int pos = numbers.length - 1;
        while (pos >= 0) {
            int t = numbers[pos];
            pos--; // 表示栈发生出栈
            while (!arrayList.isEmpty() && arrayList.get(arrayList.size() - 1) > t) {
                pos++;
                numbers[pos] = arrayList.get(arrayList.size() - 1); // 进栈
                arrayList.remove(arrayList.size() - 1); // 出栈
            }
            arrayList.add(t);
        }
        
        Collections.reverse(arrayList); // 因为觉得栈顶应该为arrayList最后一个元素。与题本身不一致，逆序一下。
        return arrayList;
    }
}