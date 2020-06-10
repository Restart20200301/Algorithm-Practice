/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* p) {
    struct ListNode* prev = NULL;
    while (p) {
        struct ListNode* q = p->next;
        p->next = prev;
        prev = p;
        p = q; 
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    int len = 0;
    struct ListNode *p, *q;
    p = q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    q = reverseList(p);
    p = head;
    while (q && p) {
        if (p->val != q->val) return false;
        p = p->next;
        q = q->next;
    }
    // 如果需要可以把list再反转还原回来
    return true; 
}