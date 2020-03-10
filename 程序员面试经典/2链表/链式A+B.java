/**
有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位
排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
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
public class Plus {
    public ListNode plusAB(ListNode a, ListNode b) {
        // write code here
        ListNode head = new ListNode(0);
        ListNode p = head;
        int t = 0;
        while (a != null || b != null || t > 0) {
            if (a != null) {
                t += a.val;
                a = a.next;
            }
            if (b != null) {
                t += b.val;
                b = b.next;
            }
            p.next = new ListNode(t % 10);
            t /= 10;
            p = p.next;
        }
        return head.next;
    }
}