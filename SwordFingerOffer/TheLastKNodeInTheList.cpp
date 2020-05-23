/**
 * 输入一个链表，输出该链表中倒数第k个结点。
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p = pListHead;
        while (p && k) {
            p = p->next;
            k--;
        }
        if (k > 0)
            return nullptr;
        while (p) {
            pListHead = pListHead->next;
            p = p->next;
        }
        return pListHead;
    }
};