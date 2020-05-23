/**
输入一个链表，输出该链表中倒数第k个结点。
 */

 /*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindKthToTail(ListNode head, int k) {
        ListNode p = head;
        while (p != null && k > 0) {
            p = p.next;
            k--;
        }
        if (k != 0)
            return null;
        while (p != null) {
            p = p.next;
            head = head.next;
        }
        return head;
    }
}