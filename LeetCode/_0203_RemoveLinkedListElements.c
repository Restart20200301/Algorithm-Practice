/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* p = head;
    struct ListNode headNode;
    headNode.next = head;
    struct ListNode* prev = &headNode;
    while (p) {
        struct ListNode* next = p->next;
        if (p->val == val) {
            free(p);
            prev->next = next;
        } else {
            prev = p;
        }
        p = next;
    } 
    return headNode.next;
}