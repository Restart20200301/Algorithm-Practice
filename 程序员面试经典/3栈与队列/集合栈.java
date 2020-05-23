/**
请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。
该数据结构应支持与普通栈相同的push和pop操作。
给定一个操作序列int[][2] ope(C++为vector&ltvector&ltint>>)，每个操作的第一个数代表操作类型，若为1，
则为push操作，后一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
请返回一个int[][](C++为vector&ltvector&ltint>>)，为完成所有操作后的SetOfStacks，顺序应为从下到上，
默认初始的SetOfStacks为空。保证数据合法。
 */

 import java.util.*;

public class SetOfStacks {
    public ArrayList<ArrayList<Integer>> setOfStacks(int[][] ope, int size) {
        // write code here
        ArrayList<ArrayList<Integer>> arrayList = new ArrayList<ArrayList<Integer>>();
        
        for (int i = 0; i < ope.length; i++) {
            if (ope[i][0] == 1) {
                boolean added = false;
                for (int j = 0; j < arrayList.size(); j++) {
                    if (arrayList.get(j).size() < size) {
                        arrayList.get(j).add(ope[i][1]);
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    ArrayList<Integer> array = new ArrayList<Integer>();
                    array.add(ope[i][1]);
                    arrayList.add(array);
                }
            } else {
                for (int j = arrayList.size() - 1; j >= 0; j--) {
                    if (!arrayList.get(j).isEmpty()) {
                        arrayList.get(j).remove(arrayList.get(j).size() - 1);
                        break;
                    }
                }
            }
        }

        return arrayList;
    }
}