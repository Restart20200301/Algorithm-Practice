/**
请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
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
public class Palindrome {
    public boolean isPalindrome(ListNode pHead) {
        // write code here
        List<Integer> stack = new ArrayList<>();
        ListNode slow = pHead, fast = pHead;
        while (fast != null && fast.next != null) {
            stack.add(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }
        // 链表长度为奇数
        if (fast != null) slow = slow.next;
        int pos = stack.size();
        while (slow != null) {
            if (slow.val != stack.get(pos - 1))
                return false;
            pos--;
            slow = slow.next;
        }
        return true;
    }
}