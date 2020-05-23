/**
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 */

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if (head)
            print(head, vec);
        return vec;
    }

    void print(ListNode* p, vector<int>& vec) {
        if (p->next)
            print(p->next, vec);
        vec.push_back(p->val);
    }
};