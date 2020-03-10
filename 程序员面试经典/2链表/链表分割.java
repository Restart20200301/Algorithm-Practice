/**
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后
保持原来的数据顺序不变。
 */

 import java.util.*;

/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Partition {
    public ListNode partition(ListNode p, int x) {
        // write code here
        ListNode beforeStart = null;
        ListNode beforeCur = null;
        ListNode afterStart = null;
        ListNode afterCur = null;
        while (p != null) {
            ListNode next = p.next;
            p.next = null;
            if (p.val < x) {
                if (beforeStart == null) {
                    beforeStart = beforeCur = p;
                } else {
                    beforeCur.next = p;
                    beforeCur = p;
                }
            } else {
                if (afterStart == null) {
                    afterStart = afterCur = p;
                } else {
                    afterCur.next = p;
                    afterCur = p;
                }
            }
            p = next;
        }
        if (beforeCur == null) {
           return afterStart;
        }
        beforeCur.next = afterStart;
        return beforeStart;
    }
}